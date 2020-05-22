/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference? */

#include <stdio.h>

#define TABS 4
#define BLANK 0
#define WORD 1

int main()
{
    int c;
    int state = BLANK;
    int numblanks = 0;

    while ((c = getchar()) != EOF)
    {
        switch (state)
        {
        case BLANK:
            if (c == ' ' || c == '\t')
                numblanks++;
            else
            {
                for (int i = 0; i < numblanks / TABS; i++)
                    printf("TAB");
                for (int i = 0; i < numblanks % TABS; i++)
                    printf("BLNK");
                numblanks = 0;
                printf("%c", c);
                state = WORD;
            }
            break;
        case WORD:
            if (c == ' ' || c == '\t')
            {
                numblanks++;
                state = BLANK;
            }
            else
                printf("%c", c);
        }
    }
    return 0;
}
