#include <stdio.h>

// function prototype declaration
float double_my_number(float n);


int main() {
  // declare variable that will contain user input
  float user_input;

  // prompt user and then read their input from console
  printf("Please enter a number that you want doubled:\n");
  scanf("%f", &user_input);
  printf("The value in user_input is: %f \n", user_input);

  // call a function and capture what it returns
  float return_value = double_my_number(user_input);

  // print the original variable that was passed
  printf("The value in user_input is: %f \n", user_input);
  // print the returned value of our function
  printf("The value that was returned from double_my_number was: %f\n", return_value);

  return 0;
}


// function definition
float double_my_number(float n)
{
  n = n * 2;

  return n;
}
