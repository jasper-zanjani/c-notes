// The file descriptors for STDIN, STDOUT, and STERR are defined as symbolic constants in unistd.h.

#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("Value of STDIN_FILENO: %d\n", STDIN_FILENO);
    printf("Value of STDOUT_FILENO: %d\n", STDOUT_FILENO);
    printf("Value of STDERR_FILENO: %d\n", STDERR_FILENO);
    return 0;
}
