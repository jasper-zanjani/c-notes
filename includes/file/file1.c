#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE* fptr;

    fptr = fopen("/home/jasper/hw", "w");
    if (fptr == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    else    
        printf("File created successfully.\n");
    exit(EXIT_SUCCESS);
} // From https://www.geeksforgeeks.org/basics-file-handling-c/#file-pointer-in-c
