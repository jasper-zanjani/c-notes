#include <unistd.h>

int main(int argc, char** argv)
{
    int g;

    while ((g = getopt (argc, argv, "a")) != -1)
    switch (g) 
    {
        case 'a':
            break;
        case '?':
            printf("Unknown option\n");
        default:
            return 1;
    }
    return 0;
}