/* Exercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table. */

#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    celsius = LOWER;

    while (celsius <= UPPER)
    {
        fahr = ((9.0 / 5.0) * celsius) + 32.0;
        printf("%3.0f %6.1f\n", fahr, celsius);
        celsius = celsius + STEP;
    }
    return 0;
}