#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define MAX 50

double a[MAX];
int top = -1;

void push(double c)
{
    a[++top] = c;
}

double pop()
{
    return a[top--];
}

double evaluate(double op2, double op1, char op)
{
    switch (op)
    {
    case '+':
        return op2 + op1;

    case '*':
        return op2 * op1;

    case '%':
        return fmod(op1, op2);

    case '/':
        return op1 / op2;

    case '^':
        return pow(op1, op2);

    case '-':
        return op1 - op2;
    }
}

void postfix()
{
    while (top != -1)
    {
        pop();
    }
    char s[20], op;
    double op1, op2, r, res;
    printf("Enter postfix expression: ");
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            push(s[i] - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();
            op = s[i];
            r = evaluate(op2, op1, op);
            push(r);
        }
    }
    res = pop();
    printf("%lf", res);
    while (top != -1)
    {
        pop();
    }
}

void prefix()
{
    while (top != -1)
    {
        pop();
    }
    char s[20], op;
    double op1, op2, r, res;
    printf("Enter prefix expression: ");
    scanf("%s", s);
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            push(s[i] - '0');
        }
        else
        {
            op1 = pop();
            op2 = pop();
            op = s[i];
            r = evaluate(op2, op1, op);
            push(r);
        }
    }
    res = pop();
    printf("%lf", res);
    while (top != -1)
    {
        pop();
    }
}

int main()
{
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("Menu:\n");
        printf("1.Postfix\n");
        printf("2.Prefix\n");
        printf("3.Exit\n");
        int c;
        printf("Enter your choice: ");
        scanf("%d", &c);
        printf("\n--------------------------------------\n");
        switch (c)
        {
        case 1:
            postfix();
            break;
        case 2:
            prefix();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!!!\n");
        }
    }
    return 0;
}