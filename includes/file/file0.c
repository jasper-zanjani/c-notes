#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    FILE* fptr;

    fptr = fopen("/home/jasper/none", "r");
    if (fptr == NULL) {
        printf("Nonexistent file failed to open.\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
} // From https://www.geeksforgeeks.org/basics-file-handling-c/#file-pointer-in-c
