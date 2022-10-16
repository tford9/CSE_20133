#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int n_out_of_bounds = atoi(argv[1]);
  argc += n_out_of_bounds;
  printf("Going %d spaces past the end of our argv.\n", n_out_of_bounds);

  for(int i = 2; i < n_out_of_bounds+2; i++)
  {
    printf("%s\n", argv[i]);
  }

  return 0;
}
