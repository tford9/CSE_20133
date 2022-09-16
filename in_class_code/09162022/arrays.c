#include <stdio.h>

int main() {

  // a single integer
  int a = 5;

  // a array containing many integers
  int my_arr[] = {1,2,3,4,5};

  // my_arr isn't actually containing data, it's a pointer to a contiguous space
  // containing numbers
  printf("%p\n", my_arr);
  printf("In the first position (%p) of my_arr is: %d \n", &my_arr[0], my_arr[0]);
  printf("In the second position (%p) of my_arr is: %d \n", &my_arr[1], my_arr[1]);

  return 0;
}
