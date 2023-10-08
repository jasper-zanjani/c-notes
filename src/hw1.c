#include <stdio.h>

int main() {
    if (fork()) // i.e. anything but 0
        printf("I am the parent\n");
    else 
        printf("I am the child\n");
}
