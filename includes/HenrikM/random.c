#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int random_number = rand() % 2;
    printf("Random number: %d\n", random_number);
    return 0;
}
