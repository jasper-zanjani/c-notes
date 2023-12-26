/*
Open and close a file, with proper error handling.
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int fd;

    fd = open("/home/jasper/.bashrc", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    else 
        printf("File opened successfully\n");
        close(fd);
        exit(EXIT_SUCCESS);
}
