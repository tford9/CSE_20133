#include <stdio.h>

int main(int argc, char const *argv[]) {

  printf("argc is %d\n", argc);
  printf("argc is located @%p\n", &argc);

  // printf("argv is %d\n",  argv);
  printf("argv is located @%p\n", argv);

  return 0;
}
