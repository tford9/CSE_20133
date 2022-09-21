#include <stdio.h>

void show(void *, int, int);


int main()
{
    int w = 40;
    int h = 40;

    unsigned int board[w][h];

    show(board, w, h);

}

void show(void *b, int w, int h)
{

    int (*current_board)[w] = b;

    /* your code goes here print out each value in each cell in a grid */ 

    fflush(stdout);

}
