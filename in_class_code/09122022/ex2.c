#include <stdio.h>

int main()
{
    int a = 4;
    int b = 10;

    printf("\n\n");

    if (!(a>b) && (a>b)){
        printf("a=%d and b=%d. a is greater than b.",a, b);
    } else {
        printf("a=%d and b=%d. a is not greater than b.",a, b);
    }
  
    printf("\n\n");

    return 0;
}

