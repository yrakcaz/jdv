#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

# include "body.h"
# include "map.h"

void run(int width, int height);
void run_with_mapping(char *map);

#endif /* !GAME_H */
