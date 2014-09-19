#ifndef MAP_H
# define MAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/stat.h>

char **get_mapping(const char *path, size_t *width, size_t *height);

#endif /* !MAP_H */
