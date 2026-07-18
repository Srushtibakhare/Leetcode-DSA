#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s)
{
    int n = strlen(s);

    char *stack = (char *)malloc(n * sizeof(char));

    int top = -1;

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }
        else
        {
            if (top == -1)
            {
                free(stack);
                return false;
            }

            if ((ch == ')' && stack[top] != '(') ||
                (ch == '}' && stack[top] != '{') ||
                (ch == ']' && stack[top] != '['))
            {
                free(stack);
                return false;
            }

            top--;
        }
    }

    bool ans = (top == -1);

    free(stack);

    return ans;
}

int main()
{
    char s[] = "({[]})";

    if (isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}