/* Exercise 1-12. Write a program that prints its input one word per line. */

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
            if (c != ' ' && c != '\t' && c != '\n')
            {
                printf("%c", c);
                state = WORD;
            }
            break;

        case WORD:
            if (c == ' ' || c == '\t' || c == '\n')
            {
                printf("\n");
                state = BLANK;
            }
            else
            {
                printf("%c", c);
            }
            break;
        }
    }
    return 0;
}
