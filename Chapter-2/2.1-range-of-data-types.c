/* Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.*/

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("Signed Char Min: %d\n", SCHAR_MIN);
    printf("Signed Char Max: %d\n", SCHAR_MAX);
    printf("Unsigned Char Max: %d\n\n", UCHAR_MAX);

    printf("Signed Short Min: %d\n", SHRT_MIN);
    printf("Signed Short Max: %d\n", SHRT_MAX);
    printf("Unsigned Short Max: %d\n\n", USHRT_MAX);

    printf("Signed Int Min: %d\n", INT_MIN);
    printf("Signed Int Max: %d\n", INT_MAX);
    printf("Unsigned Int Max: %u\n\n", UINT_MAX);

    printf("Signed Long Min: %ld\n", LONG_MIN);
    printf("Signed Long Max: %ld\n", LONG_MAX);
    printf("Unsigned Long Max: %lu\n\n", ULONG_MAX);

    return 0;
}