#include <stdio.h>

int unbounded_recursion();

int main()
{

  unbounded_recursion();

  return 0;

}

int unbounded_recursion()
{
  printf("unbounded_recursion has been called.\n");
  double arr[10000];
  unbounded_recursion();
  return 0;
}
