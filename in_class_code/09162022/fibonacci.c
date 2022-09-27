#include <stdio.h>

int print_n_fibonaccis(int *);

int main() {
  // declare variable that will contain user input
  int user_input;

  // prompt user and then read their input from console
  printf("Please enter how many fibonacci numbers you want.\n");
  scanf("%d", &user_input);
  int expression = 12*2;
  int return_value = print_n_fibonaccis(&user_input);

  printf("There, I gave you %d number of fibs.\n", user_input);

  return 0;
}

int print_n_fibonaccis(int* n_ptr)
{
  int next_fib, current_fib, previous_fib;

  previous_fib = 0;
  current_fib = 1;

  int i;
  for (i = 0; i < *n_ptr; i++){
    next_fib = current_fib + previous_fib;
    printf("Fib: %d \n", previous_fib);
    previous_fib = current_fib;
    current_fib = next_fib;
  }

  *n_ptr = 123.0;

  return 0;
}
