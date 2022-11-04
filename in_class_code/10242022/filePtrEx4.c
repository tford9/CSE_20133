#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    
    // GOOD FILE HANDLING
    /* File Names */
    char *good_filename = "newFile.txt";
    
    /* Try to get pointers to the files in write mode */
    FILE *file_pointer_1 = fopen(good_filename,"w");

    if(file_pointer_1 == NULL){
        fprintf(stderr, "File: %s does not exist!\n", good_filename);
    } else {
        fprintf(stdout, "File %s loaded successfully!\n", good_filename);
        
        // LETS TRY TO WRITE SOME NUMBERS TO THE FILE
        
        // one string at a time

        for(int i=0; i < 1000; i+=10)
        {
            // you'll need a buffer to store the string. I expect no greater than 10 digit numbers.
            char number_string[10] = "0000000000";
            sprintf(number_string, "%d", i);
            fputs(number_string, file_pointer_1);
            fputs(" ", file_pointer_1);
        }

        fclose(file_pointer_1);
    }

    return 0;
}
