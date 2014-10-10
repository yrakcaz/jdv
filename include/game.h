#ifndef GAME_H
# define GAME_H

# define _BSD_SOURCE ||                                             \
         (_XOPEN_SOURCE >= 500 ||                                   \
          _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED) &&               \
          !(_POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700)

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# include "body.h"
# include "map.h"

void run(int width, int height);
void run_with_mapping(char *map);

#endif /* !GAME_H */
