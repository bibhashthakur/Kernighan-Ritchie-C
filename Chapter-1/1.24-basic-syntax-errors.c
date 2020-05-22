/* Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full generality.) */

/* My current implementation does not check comments */

#include <stdio.h>

#define STACKLEN 100

int main()
{
    int c;
    char stack[STACKLEN];
    int top = -1;
    char error = 0;

    char singleq = 0;
    char doubleq = 0;
    char lookforescseq = 0;
    //char comm

    while ((c = getchar()) != EOF)
    {
        if (stack[top] == '\\')
        {
            switch (c)
            {
            case '0':
            case 'a':
            case 'b':
            case 'f':
            case 'n':
            case 'r':
            case 't':
            case 'v':
            case '\\':
            case '?':
            case '\'':
            case '"':
                top--;
                break;
            default:
                printf("Undefined Escape sequence: \\%c\n", c);
                error = 1;
            }
            if (error)
                break;
        }
        //printf("Input: %c %d\n", c, c);
        else if (c == '(' || c == '{' || c == '[' || c == '\\')
        {
            //printf("%c\n", c);
            stack[++top] = c;
        }
        else if (c == 39)
        {
            if (singleq == 0)
            {
                stack[++top] = c;
                //printf("%c\n", stack[top]);
                singleq = 1;
            }
            else
            {
                if (stack[top] == 39)
                {
                    top--;
                    singleq = 0;
                }
                else
                {
                    error = 1;
                    printf("Error processing '\n");
                    break;
                }
            }
        }
        else if (c == '"')
        {
            if (doubleq == 0)
            {
                stack[++top] = c;
                doubleq = 1;
            }
            else
            {
                if (stack[top] == '"')
                {
                    top--;
                    doubleq = 0;
                }
                else
                {
                    error = 1;
                    break;
                }
            }
        }
        else if (c == ')' && stack[top] == '(')
            top--;
        else if (c == '}' && stack[top] == '{')
            top--;
        else if (c == ']' && stack[top] == '[')
            top--;
    }
    if (error == 0 && top == -1)
        printf("Program compiled successfully.\n");
    else
        printf("Syntax Error: Mismatched symbol: %c. Top= %d\n", stack[top], top);
    return 0;
}