#include "conways_game_utilities.h"

int main(int argc, char *argv[])
{
    int w,h;

    if(argc == 3){
        w = atoi(argv[1]);
        h = atoi(argv[2]);
    } else {
        w = 100;
        h = 100;
    }

    game_runner(w,h);
    return 0;
}
