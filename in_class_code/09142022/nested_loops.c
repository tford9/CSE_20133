#include <stdio.h>
// this code contains an error
int main ()
{
    int i = 0;
    int j = 0;
    while (i <= 255)
    {
        while (j <= 255)
        {
            printf("i = %d - j = %d \n", i, j);
            j++;
        }
        i++;
    }
}
