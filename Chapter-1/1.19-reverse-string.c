/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time.*/

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

void reverse(char line[], int len)
{
    char temp;
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = line[j];
        line[j] = line[i];
        line[i] = temp;
    }
}

int main()
{

    char line[MAXLEN];
    int length;

    while ((length = getLine(line)) > 0)
    {
        reverse(line, length);
        printf("%s", line);
    }
    return 0;
}