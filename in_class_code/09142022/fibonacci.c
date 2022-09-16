#include <stdio.h>

int fib_n(int n);

int main() {
  int user_input;


  printf("Please enter how many fibonacci numbers you want.\n")
  scanf("%d", &user_input);

  fib_n(user_input);

  return 0;
}

int fib_n(int n)
{
  int next_fib, current_fib, previous_fib;

  previous_fib = 0;
  current_fib = 1;

  printf("You wanted %d fib numbers? Too late.\n", n);

  int i;
  for (i = 0; i < user_input; i++){
    next_fib = current_fib + previous_fib;
    printf("Fib: %d \n", previous_fib);
    previous_fib = current_fib;
    current_fib = next_fib;
  }
 
}
