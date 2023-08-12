#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char filenames[5][20] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

    
    for (int i = 0; i < 5; i++) {
        FILE *file = fopen(filenames[i], "w");
        if (file == NULL) {
            perror("Error creating file");
            exit(EXIT_FAILURE);
        }
        fprintf(file, "This is file %d.\n", i+1);
        fclose(file);
    }

   
    while (1) {
        
    }

    return 0;
}
