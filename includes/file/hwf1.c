#include <stdio.h>
#include <stdlib.h>

int main (int c, char** argv) {
   FILE* fp;

   fp = fopen ("/home/jasper/hw", "w+");
   fprintf(fp, "Hello, %s!\n", argv[1]);
   fclose(fp);
   exit(EXIT_SUCCESS);
}