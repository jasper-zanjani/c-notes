#include <stdio.h>

int main(int argc, char** argv) {
    int f;
    for(f=1; f<argc; f++) {
        printf("Hello, %s!\n", argv[f]);
    }
}
