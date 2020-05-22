/* Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

#define WORD_COUNT 10

void main()
{
    int c;
    int word_counts[WORD_COUNT + 1] = {0};
    int startidx, endidx;
    startidx = endidx = 0;
    int maxcount = 0;

    while ((c = getchar()) != EOF)
    {
        if (c < 'a' || c > 'z')
        {
            if (startidx == endidx)
            {
                startidx++;
                endidx++;
            }
            else
            {
                printf("%d %d\n", startidx, endidx);
                word_counts[endidx - startidx]++;
                startidx = endidx;
            }
        }
        else
        {
            endidx++;
        }
    }

    //printf("%d %d\n", startidx, endidx);
    //word_counts[endidx - startidx + 1]++;

    for (int i = 0; i < WORD_COUNT; i++)
    {
        if (word_counts[i] > maxcount)
        {
            maxcount = word_counts[i];
        }
    }

    printf("%d\n", maxcount);
    while (maxcount > 0)
    {
        for (int j = 1; j <= WORD_COUNT; j++)
        {
            if (maxcount == word_counts[j])
            {
                printf("*  ");
                word_counts[j]--;
            }
            else
            {
                printf("   ");
            }
        }
        printf("\n");
        maxcount--;
    }

    for (int j = 1; j <= WORD_COUNT; j++)
    {
        printf("%d  ", j);
    }
}