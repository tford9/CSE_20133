#include <stdio.h>

int factorial(int);

int main()
{
  // declare variable for user's input
  int user_input;

  // read user input from the console
  printf("\n\nPlease enter a positive integer to factorialize: \n");
  scanf("%d", &user_input);

  int factorial_result = factorial(user_input);

  printf("\n%d!=%d \n\n", user_input, factorial_result);

  return 0;
}
