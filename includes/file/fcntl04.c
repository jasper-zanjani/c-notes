/*
Write Hello, World! to a file, or create one if it doesn't exist
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd;
    char* message = "Hello, World!\n";

    fd = open("/home/jasper/hw", O_CREAT | O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    else 
        write(fd, message, strlen(message));
        close(fd);
        exit(EXIT_SUCCESS);
}
