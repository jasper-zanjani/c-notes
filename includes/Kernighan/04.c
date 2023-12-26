#include <stdio.h>

int main() 
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit\tCelsius\n----------\t-------\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        
        // These templates are apparently called "conversion specifications" and define 
        // spaces reserved for digits. This makes them suitable for designing tabular output.
        printf("%10d\t%7d\n", fahr, celsius);
        fahr = fahr + step;
    }
}