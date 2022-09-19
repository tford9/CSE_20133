#include <stdio.h>

int product(int [], int);

int main() {

  // a array containing many integers
  int my_arr[] = {1,2,3,4,5};

  // my_arr isn't actually containing data, it's a pointer to a contiguous space
  // containing numbers

  int len = sizeof(my_arr)/sizeof(my_arr[0]);
  printf("This array has %d elements.\n", len);
  printf("The product of everything in the array is: %d\n", product(my_arr, len));

  return 0;
}

int product(int arr[], int arr_len)
{
    int total = 1;

    for (int i = 0; i < arr_len; i++){
        total *= arr[i];
    }
    return total;
}
