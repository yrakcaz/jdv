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

/**
** @fn void run(int width, int height);
** @brief Principal loop which launches the game without mapping.
** @param width Width of the matrix which run has to create.
** @param height Height of the matrix which run has to create.
*/
void run(int width, int height);

/**
** @fn void run_with_mapping(char *map);
** @brief Principal loop which launches the game with a mapping file.
** @param map Path of the mapping file.
*/
void run_with_mapping(char *map);


#endif /* !GAME_H */
