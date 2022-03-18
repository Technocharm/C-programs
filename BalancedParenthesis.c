#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

int top = -1;
char a[MAX];

void push(char s)
{
    a[++top] = s;
}

char pop()
{
    return a[top--];
}

int main()
{
    char s[50];
    int flag = 0, c;
    while (1)
    {
        printf("MENU:\n");
        printf("1.Check\n");
        printf("2.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);
        if (c == 1)
        {
            printf("Enter Expression: ");
            scanf("%s", s);
            for (int i = 0; i < strlen(s); i++)
            {
                if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
                {
                    push(s[i]);
                }
                if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']'))
                {
                    if ((s[i] == ')') && ('(' == pop()))
                    {
                        flag = 1;
                    }
                    else if ((s[i] == '}') && ('{' == pop()))
                    {
                        flag = 1;
                    }
                    else if ((s[i] == ']') && ('[' == pop()))
                    {
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
            }
            if (flag)
            {
                printf("Balanced\n");
            }
            else
            {
                printf("Not Balanced\n");
            }
        }
        if (c == 2)
        {
            exit(0);
        }
    }
    return 0;
}