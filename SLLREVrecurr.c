#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *n;
n start = NULL;

n create()
{
    n newnode = (n)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    newnode->link = NULL;
    return newnode;
}

void create_list()
{
    int num;
    printf("Enter the no of elements: ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        n newnode = create();
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            newnode->link = start;
            start = newnode;
        }
    }
}

void reverse(n p)
{
    if (p->link == NULL)
    {
        start = p;
        return;
    }
    reverse(p->link);
    n q = p->link;
    q->link = p;
    p->link = NULL;
}

void display()
{
    n temp = start;
    int c = 0;
    while (temp)
    {
        printf(" -> %d", temp->data);
        temp = temp->link;
        c++;
    }
    printf("\nTotal node: %d\n", c);
}

int main()
{
    create_list();
    printf("--------------------\n");
    printf("before reverse: \n");
    display();
    reverse(start);
    printf("--------------------\n");
    printf("after reverse: \n");
    display();
    printf("--------------------\n");
    return 0;
}