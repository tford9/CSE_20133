#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {

  // variable to hold UTC time in seconds
  time_t t;
  // Intializes random number generator
  srand((unsigned) time(&t));

  int * ptr;

  if (rand() % 2)
  {
    ptr = (int*)malloc(sizeof(int));
  } else {
    ptr = NULL;
  }


  if(!ptr)
  {
    printf("ptr is NULL!\n");
  }
  else
  {
    printf("ptr is NOT NULL!\n");
  }

  return 0;
}
