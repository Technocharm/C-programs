#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *n;
n front = NULL;
n rear = NULL;

n create(int ele)
{
    n newnode = (n)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->link = NULL;
}

void create_list(int ele)
{
    n newnode = create(ele);
    if (rear == NULL && front == NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
    }
}

void enqueue(int ele)
{
    create_list(ele);
    printf("Inserted\n");
}

int dequeue()
{
    if (rear == NULL && front == NULL)
    {
        printf("Empty\n");
        return -1;
    }
    else if (front->link == NULL)
    {
        int ele = front->data;
        front = NULL;
        rear = NULL;
        return ele;
    }
    else
    {
        int ele = front->data;
        front = front->link;
        return ele;
    }
}

void display()
{
    if (rear == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        n temp = front;
        while (temp != rear)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("%d ", temp->data);
    }
}

int main()
{
    int c, ele, m;
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("MENU\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);
        printf("\n--------------------------------------\n");
        switch (c)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &ele);
            enqueue(ele);
            //display();
            break;
        case 2:
            m = dequeue();
            if (m == -1)
            {
                printf("Empty\n");
            }
            else
            {
                printf("Element deleted %d\n", m);
            }
            //display();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Input!!!\n");
            break;
        }
    }
    return 0;
}