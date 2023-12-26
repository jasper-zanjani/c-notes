#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE* fptr;
    char buffer[50];

    fptr = fopen("/home/jasper/.bashrc", "r");
    if (fptr == NULL) 
        printf(".bashrc file failed to open.\n");
    else {
        printf("The file is now opened.\n");
        while (fgets(buffer, 50, fptr) != NULL) {
            printf("%s", buffer);
        }
        fclose(fptr);
        printf(".bashrc is now closed.");
    }

    return 0;
} // From https://www.geeksforgeeks.org/basics-file-handling-c/#file-pointer-in-c
