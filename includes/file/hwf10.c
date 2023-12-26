#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    int fd;

    fd = open("/home/jasper/hw", O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror(open);
        return 1;
    }
    write(fd, "Hello, World!\n", 13);
    close(fd);
    return 0;
}
