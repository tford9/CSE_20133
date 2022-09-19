#include <stdio.h>

int main() {

  // a array containing many integers
  char my_char_arr[] = {'H','e','l','l','o','\0'};

  // points to an address still 
  printf("my_char_arr points to: %p\n", my_char_arr);

  // using %s to print the character array pointer
  printf("my_char_arr contains:  %s\n", my_char_arr );

  return 0;
}
