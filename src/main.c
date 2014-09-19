#include <string.h>
#include "../include/game.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc != 3)
        printf("jdv: invalid arguments: must take 2 arguments which represents width and height or --map/-m then the mapping file\n");
    else if (!strcmp(argv[1], "-m") || !strcmp(argv[1], "--map"))
        run_with_mapping(argv[2]);
    else
        run(atoi(argv[1]), atoi(argv[2]));
    return 0;
}
