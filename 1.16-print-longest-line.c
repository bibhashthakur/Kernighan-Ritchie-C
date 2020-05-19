/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the
length of arbitrary long input lines, and as much as possible of the text. */

#include <stdio.h>

#define MAXLEN 10

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

void copy(char source[], char dest[])
{
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

int main()
{
    int c, longest = 0, thislength = 0, maxlength = 0;
    char longestline[MAXLEN];
    char thisline[MAXLEN];

    while ((thislength = getLine(thisline)) > 0)
    {
        if (thislength > maxlength)
        {
            copy(thisline, longestline);
            maxlength = thislength;
        }
    }
    printf("%s", longestline);
    return 0;
}