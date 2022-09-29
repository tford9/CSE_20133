#include <stdio.h>
#include <stdlib.h>

void show(void *, int, int);
void board_initializer(void *,int,int);
void evolve_board(void *,int,int);

int main()
{
    int w = 40;
    int h = 40;

    int board[w][h];
    board_initializer(board, w, h);
    while(1)
    {
      show(board, w, h);
    }

}

void evolve_board(void *b, int w, int h)
{
int (*current_board)[w] = b;
int evolved_board[w][h];

for(int x = 0; x < w; i++)
{
  for(int y = 0; y < h; j++)
  {
    // get the number of living cells around each cell
    int n = 0;
    for (int y1 = y - 1; y1 <= y + 1; y1++)
    {
      for (int x1 = x - 1; x1 <= x + 1; x1++)
      {
        if (univ[(y1 + h) % h][(x1 + w) % w])
        {
          n++;
        }
      }
    }
  }
}

void show(void *b, int w, int h)
{

    int (*current_board)[w] = b;

    printf("\033[0;0H");
    printf("\033[2J");

    for(int i = 0; i < w; i++)
    {
      for(int j = 0; j < h; j++)
      {
        if(current_board[i][j]==0)
        {
          printf("  ");
        } else
        {
          printf("\033[7m  \033[27m");
        }
      }
      printf("\n");
    }
    printf("\033[E");

    /* your code goes here print out each value in each cell in a grid */

    fflush(stdout);
}

void board_initializer(void *b, int w,int h)
{
    int (*empty_board)[w] = b;

    for (int i = 0; i < w; i++)
    {

      for (int j = 0; j < h; j++)
      {
          int rand_tenth = rand() % 10;
          // printf("%d\n", rand_tenth);
          if(rand_tenth == 0){
              empty_board[i][j] = 1;
          } else
          {
             empty_board[i][j] = 0;
          }

      }
    }
}
