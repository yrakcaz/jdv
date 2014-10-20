#include "../include/map.h"

static int check_map(char *buf, size_t *size, size_t *width, size_t *height)
{
    for (size_t i = 0; i < *size; i++)
        if (buf[i] != '.' && buf[i] != '*' && buf[i] != '\n')
            return -1;
    size_t n = 0;
    for (int i = *size - 1; i >= 0; i--)
    {
        if (buf[i] != '\n')
            break;
        else
        {
            buf[i] = '\0';
            n++;
        }
    }
    *size -= n;
    for (*width = 0; *width < *size && buf[*width] != '\n'; (*width)++) {}
    n = 0;
    *height = 0;
    for (size_t i = 0; i < *size + 1; i++)
    {
        if (buf[i] == '\n' || i == *size)
        {
            *height += 1;
            if (n != *width)
                return -1;
            n = 0;
        }
        else
            n++;
    }
    return (*width > 1 && *height > 1);
}

char **get_mapping(const char *path, size_t *width, size_t *height)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        printf("jdv: %s: no such file or directory.\n", path);
        exit(1);
    }
    struct stat st;
    fstat(fd, &st);
    char *buf = malloc(st.st_size * sizeof (char));
    read(fd, buf, st.st_size);
    close(fd);
    if (check_map(buf, (size_t *)&(st.st_size), width, height) == -1)
    {
        free(buf);
        printf("jdv: %s: the map is incorrect, it has to contain only points and stars, and every lines must have same size.\n", path);
        exit(1);
    }
    char **ret = malloc(*width * sizeof (char *));
    for (size_t i = 0; i < *width; i++)
        ret[i] = malloc(*height * sizeof (char));
    int i = 0;
    int j = 0;
    for (int c = 0; c < st.st_size; c++)
    {
        if (buf[c] == '\n')
        {
            i = 0;
            j++;
        }
        else
        {
            ret[j][i] = buf[c] == '*' ? 1 : 0;
            i++;
        }
    }
    free(buf);
    return ret;
}

