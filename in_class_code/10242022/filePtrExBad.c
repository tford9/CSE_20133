#include <stdio.h>

int main(){
    
    // BAD FILE HANDLING
    /* File Names */
    char *bad_filename = "fileDNE.txt";
    
    /* Try to get pointers to the files in read-only mode */
    FILE *file_pointer_DNE = fopen(bad_filename, "r");
    
    if(file_pointer_DNE == NULL){
        fprintf(stderr, "File: %s does not exist!\n", bad_filename);
    }
    
    // TRY TO CLOSE A NULL POINTER
    fclose(file_pointer_DNE);
    
    return 0;
}
