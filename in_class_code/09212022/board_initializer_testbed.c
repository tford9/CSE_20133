#include <stdio.h>
#include <stdlib.h> // included for rand() function, RAND_MAX value, and atoi() function

void board_initializer(void *, int, int);

int main()
{
    int w = 40;
    int h = 40;

    unsigned board[w][h];

    board_initializer(board, w, h);

    for (int i = 0; i < w; i++)
    {
      for (int j = 0; j < h; j++)
      {
          printf("%d ", board[i][j]);
      }
      printf("\n");
    }

    return 0;
}

void board_initializer(void *b, int w,int h)
{
    int (*empty_board)[w] = b;

    for (int i = 0; i < w; i++)
    {

      for (int j = 0; j < h; j++)
      {
          int rand_one = rand() % 2;
          printf("%d\n", rand_one);
          empty_board[i][j] = rand_one;
      }
    }
}
