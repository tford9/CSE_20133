#include <stdio.h>
#include <stdlib.h>

int main() {
  while(1)
  {
    int * arr = (int*)malloc(1000);
    free(arr);
  }
  return 0;
}
