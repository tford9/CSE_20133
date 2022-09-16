#include <stdio.h>

// function prototype declaration
int fib_n(int n);

int main() {
  // declare variable that will contain user input
  int user_input;

  // prompt user and then read their input from console
  printf("Please enter how many fibonacci numbers you want.\n")
  scanf("%d", &user_input);

  // call a function and capture what it returns
  int return_value = fib_n(user_input);

  return 0;
}

int fib_n(int n)
{
  int next_fib, current_fib, previous_fib;

  previous_fib = 0;
  current_fib = 1;

  int i;
  for (i = 0; i < user_input; i++){
    next_fib = current_fib + previous_fib;
    printf("Fib: %d \n", previous_fib);
    previous_fib = current_fib;
    current_fib = next_fib;
  }
  return 0;
}
