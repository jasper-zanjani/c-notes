/*
Write Hello, World! to a file, or create one if it doesn't exist
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;

    fd = open("/home/jasper/hw", O_CREAT | O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    else 
        write(fd, "Hello, World!\n", 14);
        close(fd);
        exit(EXIT_SUCCESS);
}
