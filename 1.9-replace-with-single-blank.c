/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank. */

#include <stdio.h>

#define BLANK 0
#define WORD 1

int main()
{
    int c;
    char state = BLANK;

    while ((c = getchar()) != EOF)
    {
        switch (state)
        {
        case BLANK:
            if (c != ' ' && c != '\t')
            {
                printf("%c", c);
                state = WORD;
            }
            break;

        case WORD:
            printf("%c", c);
            if (c == ' ' || c == '\t')
            {
                state = BLANK;
            }
            break;
        }
    }
    return 0;
}
