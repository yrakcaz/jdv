#ifndef MAP_H
# define MAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>

/**
** @fn char **get_mapping(const char *path, size_t *width, size_t *height);
** @brief Function which parses a mapping file then create a game of life table.
** @param path Path of the mapping file.
** @param width Reference passed which has to get width of the mapping file.
** @param height Reference passed which has to get height of the mapping file.
** @return Returns the initial table, represented by the mapping file.
*/
char **get_mapping(const char *path, size_t *width, size_t *height);

#endif /* !MAP_H */
