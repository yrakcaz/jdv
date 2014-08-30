#include "../include/game.h"

#define CLEAR_SCREEN_ANSI "\033[1;1H\033[2J"
#define TRESHOLD 30

/*static*/ void clear_screen()
{
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

static char **init_table(int width, int height)
{
    char **table = malloc(width * sizeof (char *));
    for (int i = 0; i < width; i++)
        table[i] = malloc(height * sizeof (char));
    for (int i = 0; i < width; i++)
        for (int j = 0; j < height; j++)
            table[i][j] = (rand() % 100) < TRESHOLD ? 1 : 0;
    return table;
}

void run(int width, int height)
{
    char **table = init_table(width, height);
    while (1)
    {
        clear_screen();
        draw(table, width, height);
        table = update(table, width, height);
        sleep(1);
    }
}
