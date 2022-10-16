#include <stdio.h>


struct Recipe
{
    char ingredients[1000];
    char instructions[1000];
};

typedef struct Recipe Recipe;

struct CookBook
{
    char author_name[100];
    Recipe recipes[1000];
};



int main(int argc, char const *argv[]) {
  
    struct CookBook CB;

    printf("CB is located: %p\n", &CB);

  return 0;
}
