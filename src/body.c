#include "../include/body.h"

static void destroy_table(char **table, int width)
{
    for (int i = 0; i < width; i++)
        free(table[i]);
    free(table);
}

static char **init_table(int width, int height)
{
    char **table = malloc(width * sizeof (char *));
    for (int i = 0; i < width; i++)
        table[i] = malloc(height * sizeof (char));
    return table;
}

static int alive_neighbours(char **tab, int i, int j, int width, int height)
{
    int count = 0;
    for (int x = i - 1; x < i + 2; x++)
    {
        for (int y = j - 1; y < j + 2; y++)
        {
            if (x < 0 || y < 0 || x > width - 1 || y > height - 1 ||
               ((x == i) && (y == j)))
                continue;
            else
            {
                if (tab[x][y] == 1)
                    count++;
            }
        }
    }
    return count;
}

char **update(char **table, int width, int height)
{
    char **ret = init_table(width, height);
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int nb = alive_neighbours(table, i, j, width, height);
            if (table[i][j] == 0 && nb == 3)
                ret[i][j] = 1;
            else if (table[i][j] == 1 && (nb != 2 && nb != 3))
                ret[i][j] = 0;
        }
    }
    destroy_table(table, width);
    return ret;
}

void draw(char **table, int width, int height)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int c = table[i][j] == 0 ? '.' : '*';
            printf("%c", c);
        }
        printf("\n");
    }
}
