#include <stdio.h>

float square(float);

int main()
{
  const int SIZE = 5;
  float numbers[] = {10.0,3.0,800.0,12.0,42.0};
  float squared_numbers[SIZE]; // declared but not initialized

  /* Your Code Goes Here */

  /*  */

  printf("\n"); // give me some space!

  for(int i = 0; i<SIZE; i++)
  {
    printf("%f squared is %f\n", numbers[i], squared_numbers[i]);
  }

  return 0;
}

float square(float n)
{
  printf("\nSquaring %f \n", n);
  float sq = n*n;
  return sq;
}
