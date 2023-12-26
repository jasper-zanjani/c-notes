#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct starship {
    char name[20];
    char registry[20];
    char class[20];
    int crew;
} Starship;

int main(int argc, char const *argv[])
{
    Starship ent, entd, voy;

    strcpy(ent.name, "USS Enterprise");
    strcpy(entd.name, "USS Enterprise");
    strcpy(voy.name, "USS Voyager");

    strcpy(ent.registry, "NCC-1701");
    strcpy(entd.registry, "NCC-1701-D");
    strcpy(voy.registry, "NCC-74656");

    strcpy(ent.class, "Constitution");
    strcpy(entd.class, "Galaxy");
    strcpy(voy.class, "Intrepid");

    ent.crew = 203;
    entd.crew = 6000;
    voy.crew = 141;

    printf("%-20s%-20s%-20s%20i\n", ent.name, ent.registry, ent.class, ent.crew);
    printf("%-20s%-20s%-20s%20i\n", entd.name, entd.registry, entd.class, entd.crew);
    printf("%-20s%-20s%-20s%20i\n", voy.name, voy.registry, voy.class, voy.crew);

    exit(EXIT_SUCCESS);
}
