#include <stdio.h>
#include <stdlib.h>

#define FILENAME "hw"

int main (int c, char** argv) {
   FILE* fp;
   
   fp = fopen (FILENAME, "r");
   if (fp == NULL) {
      printf("Error opening file.\n");
      exit(EXIT_FAILURE);
   }
   else {
      printf("File opened successfully!\n");
      fclose(fp);
   }
   exit(EXIT_SUCCESS);
}