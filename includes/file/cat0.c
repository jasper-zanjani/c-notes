#include <stdlib.h>
#include <stdio.h>

char *buffer;

void read(char* filename) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp != NULL) {
        fseek(fp, 0L, SEEK_END);
        long s = ftell(fp);
        rewind(fp);
        buffer = malloc(s);
        fread(buffer, s, 1, fp);
        fwrite(buffer, s, 1, stdout);
        if (fp != NULL) fclose(fp);
        free(buffer);
    }
}

int main(int argc, char** argv) {
    int f;
    for(f=1; f<argc; f++) {
        read(argv[f]);
    }
    exit(EXIT_SUCCESS);
}