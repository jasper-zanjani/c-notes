#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t mypid;

    mypid = getpid();
    printf("My PID is %ld\n", (long) mypid);
    return 0;
}
