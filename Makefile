EXE=jdv
CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c99 -pedantic
SRC=src/body.c src/game.c src/map.c src/main.c
OBJ=$(SRC:.c=.o)
TAR=yrakcaz-jdv
DIR=/usr/bin

-include makefile.rules

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f $(OBJ) $(EXE) $(TAR).tar.bz2

cleandoc:
	rm -rf doc/html doc/latex doc/refman.pdf

distclean: clean cleandoc
	rm -f makefile.rules

doc:
	doxygen doc/Doxyfile
	$(MAKE) -C doc/latex
	mv doc/latex/refman.pdf doc/

export:
	git archive HEAD --prefix=$(TAR)/ | bzip2 > $(TAR).tar.bz2

install:
ifeq ($(DIR),/usr/bin)
	sudo cp jdv $(DIR)
else
	cp jdv $(DIR)
endif

.PHONY: all clean distclean export doc
