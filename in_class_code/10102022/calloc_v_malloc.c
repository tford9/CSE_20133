#include <stdio.h>
#include <stdlib.h>

int main() {

  int* malloc_arr = (int*)malloc(250*sizeof(int));

  int* calloc_arr = (int*)calloc(250, sizeof(int));

  for(int i = 0; i < 250; i++)
  {
    printf("%d ", malloc_arr[i]);
  }
  printf("\n");

  for(int i = 0; i < 250; i++)
  {
    printf("%d ", calloc_arr[i]);
  }

  return 0;
}
