#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE* fptr;

    fptr = fopen("/home/jasper/none", "r");
    if (fptr == NULL) {
        perror("fopen");
        printf("errno: %d\n", errno);
        printf("strerror: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
        fclose(fptr);
    exit(EXIT_SUCCESS);
}
