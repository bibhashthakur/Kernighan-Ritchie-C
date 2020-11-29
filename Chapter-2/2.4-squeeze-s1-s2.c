/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2. */

#include <stdio.h>

#define MAXLEN 100

int getLine(char line[])
{
    int c, length = 0, i = 0;

    while (length < MAXLEN)
    {
        c = getchar();
        if (c == EOF || c == '\n')
        {
            break;
        }
        line[i++] = c;
        length++;
    }
    line[i] = '\0';
    return length;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (i = 0; s2[i] != '\0'; i++)
    {
        for (j = k = 0; s1[k] != '\0'; k++)
        {
            if (s2[i] != s1[k])
            {
                s1[j++] = s1[k];
            }
        }
        s1[j] = '\0';
    }
}

int main()
{
    int length;
    char s1[MAXLEN + 1];
    char s2[MAXLEN + 1];
    int i = 0;

    printf("Enter S1: ");
    getLine(s1);

    i = 0;
    printf("\nEnter S2: ");
    getLine(s2);

    squeeze(s1, s2);
    printf("\nAfter Squeeze: %s \n", s1);
    return 0;
}