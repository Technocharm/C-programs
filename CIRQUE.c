#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int a[MAX], front = -1, rear = -1;

int is_full()
{
    if ((rear == MAX - 1 && front == 0) || (rear + 1 == front))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_empty()
{
    if (rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int ele)
{
    if (is_full())
    {
        printf("Queue is full !!!\n");
    }
    else if (rear == -1 && front == -1)
    {
        front = 0;
        rear = (rear + 1) % MAX;
        a[rear] = ele;
    }
    else
    {
        rear = (rear + 1) % MAX;
        a[rear] = ele;
    }
}

int dequeue()
{
    if (is_empty())
    {
        return -1;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
        return a[front - 1];
    }
}

void display()
{
    int i;
    if (is_empty())
    {
        printf("Empty\n");
    }
    else
    {
        for (i = front; i != rear; i = (i + 1) % MAX)
        {
            printf("%d ", a[i]);
        }
        printf("%d ", a[i]);
    }
}

int main()
{
    int c, ele, n;
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
            // display();
            break;
        case 2:
            n = dequeue();
            if (n == -1)
            {
                printf("Empty\n");
            }
            else
            {
                printf("Element popped %d\n", n);
            }
            // display();
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