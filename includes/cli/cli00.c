#include <unistd.h>

int main(int argc, char** argv)
{
    int g;

    while ((g = getopt (argc, argv, "")) != -1)
    switch (g) 
    {
        default:
            return 1;
    }
    return 0;
}