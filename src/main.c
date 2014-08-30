#include "../include/game.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc != 3)
        printf("jdv: invalid arguments: must take 2 arguments which represents width and height\n");
    else
        run(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
