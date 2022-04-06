#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int v[MAX], a[MAX][MAX], n, q[MAX], top = -1;

int pop()
{
    int ele = q[top--];
    return ele;
}

void push(int ele)
{
    q[++top] = ele;
}

void dfs(int s)
{
    v[s] = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[s][i])
        {
            if (v[i] == 0)
            {
                dfs(i);
            }
        }
    }
    push(s);
}

int main()
{
    printf("Enter the order of the Adjacency Matrix (nXn)(DAG): ");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            dfs(i);
        }
    }
    while (top != -1)
    {
        printf("%d", pop());
    }
    return 0;
}
