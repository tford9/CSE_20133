#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define uint unsigned int
#define FOR_X for (uint x = 0; x < w; x++)
#define FOR_Y for (uint y = 0; y < h; y++)
#define FOR_XY FOR_X FOR_Y

void show(void *, uint, uint);
void board_initializer(void *, uint, uint);
void evolve_board(void *, uint, uint);

int main()
{
    uint w = 40;
    uint h = 40;

    int board[w][h];
    board_initializer(board, w, h);
    while(1)
    {
        evolve_board(board, w, h);
        show(board, w, h);
        sleep(1);
    }
}

void evolve_board(void *b, uint w, uint h) {
    int (*current_board)[w] = b;
    int evolved_board[w][h];

    FOR_XY
    {
        int n = 0;
        for (uint y1 = y - 1; y1 <= y + 1; y1++) {
            for (uint x1 = x - 1; x1 <= x + 1; x1++) {
                if (current_board[(y1 + h) % h][(x1 + w) % w]) {
                    n++;
                }
            }
        }
        if (current_board[y][x]) {
            n--;
        }
        evolved_board[y][x] = (n == 3 || (n == 2 && current_board[y][x]));
        }
    FOR_XY
    {
        current_board[y][x] = evolved_board[y][x];
    }
}

void show(void *b, uint w, uint h)
{
    int (*current_board)[w] = b;

    printf("\033[0;0H");
    printf("\033[2J");

    FOR_X
    {
      FOR_Y
      {
        if(current_board[x][y]==0)
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
    fflush(stdout);
}

void board_initializer(void *b, uint w, uint h)
{
    int (*empty_board)[w] = b;

    FOR_XY
    {
        int rand_tenth = rand() % 10;
        if(rand_tenth == 0){
            empty_board[x][y] = 1;
        } else
        {
            empty_board[x][y] = 0;
        }
    }
}
