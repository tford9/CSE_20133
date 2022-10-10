#include <stdio.h>

int main(int argc, char const ** argv)
{

  printf("The number of commands line arguments is: %d\n", argc);

  printf("The arguments are: \n");
  for(int i = 0; i < argc; i++)
  {
    printf("%s\n", argv[i]);
  }

  return 0;
}
