#include <stdio.h>

int main() {
  float user_input;
  int threshold = 283;

  scanf("%d", &user_input);

  int next_fib, current_fib, last_fib;

  last_fib = 0;
  current_fib = 1;

  printf("You wanted %d fib numbers? Too late.\n", user_input);

  for (int i = 0; i < user_input; i++){
    next_fib = current_fib + last_fib;
    printf("Current Fib: %d \n", current_fib);
    last_fib = current_fib;
    current_fib = next_fib;
  }
  return 0;
}
