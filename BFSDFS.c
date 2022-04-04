#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int a[MAX][MAX], v[MAX], e[MAX], n, front = 0, rear = -1;

int is_empty()
{
    if (rear == -1 || (front == rear + 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void create()
{
    printf("Enter the order of the Adjacency Matrix (nXn): ");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void bfs()
{
    int s, m;
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
        e[i] = 0;
    }
    printf("Enter the start node: ");
    scanf("%d", &s);
    printf("%d", s);
    v[s] = 1;
    e[++rear]=s;
    while (!is_empty())
    {
        s = e[front++];
        for (int i = 0; i < n; i++)
        {
            if (a[s][i] == 1 && v[i] == 0)
            {
                printf("%d", i);
                v[i] = 1;
                e[++rear]=i;
            }
        }
    }
}

void dfs(int s)
{
    printf("%d", s);
    v[s] = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[s][i] == 1 && v[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int c, s;
    while (1)
    {
        printf("MENU\n");
        printf("1.Create\n");
        printf("2.BFS\n");
        printf("3.DFS\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            bfs();
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                v[i] = 0;
            }
            printf("Enter the start node: ");
            scanf("%d", &s);
            dfs(s);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice!!!\n");
            break;
        }
    }
    return 0;
}