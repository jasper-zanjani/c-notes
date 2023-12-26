#include <gnu/libc-version.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Using gnu_get_libc_version(): %s\n", gnu_get_libc_version());
    printf("Using symbolic constnats: %d.%d\n", __GLIBC__, __GLIBC_MINOR__);
    return 0;
}
