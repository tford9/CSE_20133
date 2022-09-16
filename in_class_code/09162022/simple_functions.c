#include <stdio.h>

// function prototype declaration
int my_simple_function(int);

int main() {
  int number = 12;

  // call a function and capture what it returns - if anything
  int return_value = my_simple_function(number);

  // print the returned value of our function
  printf("The value that was returned from my_simple_function was: %d\n", return_value);

  return 0;
}


// function definition
int my_simple_function(int local_variable_name)
{
  printf("You passed in :%d \n", local_variable_name);

  return 0;
}
