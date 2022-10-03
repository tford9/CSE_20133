//
// Created by Trenton W. Ford on 10/3/2022.
//

#include <stdio.h>


int global_var = 14; // this variable is stored in the "data" portion of the program memory

int main()
{

    char name[] = "CSE 20133"; // this variable is stored on the stack at the start of runtime
    /*  */
    char *other_name;

    other_name = (*char)malloc(sizeof(char)*10);


}