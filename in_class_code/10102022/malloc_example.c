//
// Created by Trenton W. Ford on 10/3/2022.
//
#include <stdio.h>
#include <stdlib.h>


int main()
{
    // oversized character array
    char char_arr[256];
    // read in user input
    // gets has been deprecated and put out to pasture
    fgets(char_arr, 256, stdin);

    // find out how many characters the user entered
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

    // declare a pointer to the smaller heap allocated version of your string
    char * slim_arr;

    //ask the runtime environment for the correct space on the heap
    slim_arr = (char*)malloc(sizeof(char)*(length+1));

    // copy the characters from the oversized array into
    // the new slim_arr
    for (int i = 0; i<length; i++)
    {
      slim_arr[i] = char_arr[i];
    }

    // don't forget that a null termination character is necessary
    slim_arr[length-1] = '\0';

    printf("%s is %d characters long.", slim_arr, length);

    return 0;
}
