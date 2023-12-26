#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    char* filename;
    FILE* fptr;

    fptr = fopen("/home/jasper/hw", "r+");
    if (fptr == NULL) {
        perror("fopen");
        printf("%d\n", errno);
        exit(EXIT_FAILURE);
    }
    else {
        fputs("Hello, World!", fptr);
        fclose(fptr);
        exit(EXIT_SUCCESS);
    }
}
