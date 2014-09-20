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
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            table[i][j] = 0;
    return table;
}

static int alive_neighbours(char **tab, int i, int j, int width, int height)
{
    int n = 0;
    for (int k = i - 1; k < i + 2; k++)
        if (k >= 0 && k < width)
            for (int l = j - 1; l < j + 2; l++)
                if (l >= 0 && l < height && (k != i || l != j) && tab[k][l])
                    n++;
    return n;
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
            else if (table[i][j] == 1 && (nb == 2 || nb == 3))
                ret[i][j] = 1;
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
