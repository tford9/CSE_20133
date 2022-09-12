#include <stdio.h>

int main() {
  float user_input;
  int threshold = 283;

  scanf("%f", &user_input);
  if (threshold < user_input)
  {
    printf("Your input was greater than %d.\n", threshold);
  } else
  {
    printf("Your input was less than %d. \n", threshold);
  }

  return 0;
}
