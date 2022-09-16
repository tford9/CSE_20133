#include <stdio.h>

// function prototype declaration
float double_my_number(int n);


int main() {
  // declare variable that will contain user input
  int user_input;

  // prompt user and then read their input from console
  printf("Please enter a number that you want doubled:\n")
  scanf("%d", &user_input);

  // call a function and capture what it returns
  int return_value = double_my_number(user_input);

  return 0;
}


// function definition
float double_my_number(float n)
{
  float doubled_number = n * 2;

  return doubled_number;
}
