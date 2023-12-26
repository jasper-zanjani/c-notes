#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int g;

    while ((g = getopt (argc, argv, ":ab:")) != -1)
    switch (g) 
    {
        case 'a':
            break;
        case 'b':
            printf("Hello, %s!\n", optarg);
        case '?':
            printf("Unknown option");
            return 1;
        case ':':
            printf("Missing argument");
            return 1;
        default: 
            printf("We should never get here");
            return 1;
    }
    return 0;
}