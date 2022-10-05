//
// Created by Trenton W. Ford on 10/4/2022.
//

#include <stdio.h>
#include <stdlib.h>

#define l_uint long unsigned int

int main()
{
    l_uint user_input;
    scanf("%ld", &user_input);

    // declare a pointer to the smaller heap allocated version of your string
    // int * slim_arr;

    //ask the runtime environment for the correct space on the heap
    int * slim_arr = (int*)malloc(sizeof(int)*(user_input));

    printf("User input is %ld. We placed slim_arr @%p", user_input, slim_arr);

    free(slim_arr);

    printf("User input is %ld. We placed slim_arr @%p", user_input, slim_arr);

    return 0;
}
