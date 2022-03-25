#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char infix[50], a[50];
int top = -1;

void push(char c)
{
    a[++top] = c;
}

char pop()
{
    return a[top--];
}

void display(){
    for(int i=top;i>=0;i--){
        printf("%c\n",a[i]);
    }
}

int priority(char c)
{
    if (c == '(')
    {
        return 1;
    }
    else if (c == '+' || c == '-')
    {
        return 2;
    }
    else if (c == '*' || c == '/' || c == '%')
    {
        return 3;
    }
    else if (c == '^')
    {
        return 4;
    }
}

void postfix()
{
    char b;
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    for (int i = 0; i<strlen(infix); i++)
    {
        if (isalnum(infix[i]))
        {
            printf("%c", infix[i]);
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((b=pop()) != '(')
            {
                printf("%c", b);
            }
        }
        else
        {
            while (priority(a[top]) >= priority(infix[i]))
            {
                printf("%c", pop());
            }
            push(infix[i]);
        }
        //display();
    }
    while(top!=-1){
        printf("%c",pop());
    }  
}

int main()
{
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("Menu\n");
        printf("1.Postfix\n");
        printf("2.Exit\n");
        int c;
        printf("Enter choice: ");
        scanf("%d", &c);
        printf("\n--------------------------------------\n");
        switch (c)
        {
        case 1:
            postfix();
            break;
        case 2:
            exit(0);
        }
    }
    return 0;
}