#include <stdio.h>
#include <stdlib.h>

#define FILENAME "/home/jasper/hw"

int main(int argc, char** argv) {
    char* filename;
    FILE* fptr;

    if (argc == 1)
        filename = FILENAME;
    else
        filename = argv[1];
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    else {
        fprintf(fptr, "Hello, World!\n");
        fclose(fptr);
    }
    exit(EXIT_SUCCESS);
}   