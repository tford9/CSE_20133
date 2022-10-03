//
// Created by Trenton W. Ford on 10/3/2022.
//

#include <stdio.h>
#include <stdlib.h>

int global_var = 14; // this variable is stored in the "data" portion of the program memory

int my_other_global;

int main()
{
    //
    // char name[] = "CSE 20133"; // this variable is stored on the stack at the start of runtime
    // /*  */
    //
    // char *future_string = (*char)malloc(sizeof(char)*10);
    //
    // char *other_name = (*char)future_string;

    char char_arr[256];

    fgets(char_arr, 256, stdin);

    char * slim_arr;

    int length = 0;
    for(int i = 0; i < sizeof(char_arr)/sizeof(char); i++)
    {
      if (char_arr[i] == '\0')
        {
          break;
        } else {
          length+=1;
        }
    }

    slim_arr = (char*)malloc(sizeof(char)*(length+1));


    for (int i = 0; i<length; i++)
    {
      slim_arr[i] = char_arr[i];
    }
    slim_arr[length-1] = '\0';

    printf("%s is %d characters long.", slim_arr, length);

    return 0;
}
