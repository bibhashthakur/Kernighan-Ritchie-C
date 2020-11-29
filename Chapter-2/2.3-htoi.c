/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 100

long int htoi(const char s[])
{
    int len = strlen(s);
    long int result = 0;
    int counter = 1;
    char digit;

    for (int i = len - 1; i >= 0; i--)
    {
        digit = tolower(s[i]);
        if (s[i] == 'x')
            break;

        if (isdigit(digit))
            digit = digit - '0';
        else if (digit >= 'a' && digit <= 'f')
            digit = (digit - 'a') + 10;
        else
        {
            printf("\nInvalid Hex Number!");
            return -1;
        }
        result += digit * counter;
        counter *= 16;
    }
    return result;
}

int main()
{
    int c;
    char hex[MAXLEN + 3];
    int i = 0;
    long int result;

    printf("Enter hex number: ");
    while ((c = getchar()) != EOF)
    {
        hex[i++] = c;
    }
    hex[i] = '\0';

    result = htoi(hex);
    printf("\nConverted Integer: %ld \n", result);

    return 0;
}