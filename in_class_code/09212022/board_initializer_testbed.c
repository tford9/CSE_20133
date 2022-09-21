#include <stdio.h>
#include <stdlib.h> // included for rand() function, RAND_MAX value, and atoi() function

void board_initializer(void *, int, int);

int main()
{
    int w = 40;
    int h = 40;

    unsigned board[w][h];
    
    board_initializer(board, w, h);

    return 0;
}

void board_initializer(void *b, int w,int h)
{
    int (*empty_board)[w] = b;

    

    // now you treat empty_board like a normal array

    /* try to write a function that will initialize the positions randomly */

}
