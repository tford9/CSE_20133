#include <stdio.h>

int main(){
    
    // GOOD FILE HANDLING
    /* File Names */
    char *good_filename = "intsFile.txt";
    
    /* Try to get pointers to the files in read-only mode */
    FILE *file_pointer_1 = fopen(good_filename,"r");

    if(file_pointer_1 == NULL){
        fprintf(stderr, "File: %s does not exist!\n", good_filename);
    } else {
        fprintf(stdout, "File %s loaded successfully\n!", good_filename);
        fclose(file_pointer_1);
    }

    return 0;
}
