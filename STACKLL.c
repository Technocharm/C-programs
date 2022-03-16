#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *n;
n start = NULL;

n create(int ele)
{
    n newnode = (n)malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->link = NULL;
    return newnode;
}

void create_list(int ele)
{
    n newnode = create(ele);
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

void push(int ele)
{
    create_list(ele);
    printf("Element inserted\n");
}

int pop()
{
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else if (start->link == NULL)
    {
        int ele = start->data;
        start = NULL;
        return ele;
    }
    else
    {
        int ele = start->data;
        start = start->link;
        return ele;
    }
}

int pop1()
{
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else if (start->link == NULL)
    {
        int ele = start->data;
        start = NULL;
        return ele;
    }
    else
    {
        n temp = start;
        n prev;
        while (temp->link)
        {
            prev = temp;
            temp = temp->link;
        }
        int ele = temp->data;
        prev->link = NULL;
        free(temp);
        return ele;
    }
}

void display()
{
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        n temp = start;
        while (temp)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}

void palindrome()
{
    n temp = start;
    while (temp)
    {
        pop();
    }
    int num, c = 0, mid, i, flag = 0;
    printf("Enter no. : ");
    scanf("%d", &num);
    while (num)
    {
        push(num % 10);
        num = num / 10;
        c++;
    }
    if (c % 2 == 0)
    {
        mid = c / 2;
    }
    else
    {
        mid = (c + 1) / 2;
    }

    for (i = 0; i < (int)mid - 1; i++)
    {
        if (pop1() == pop())
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("It's a palindrome :) \n");
    }
    else
    {
        printf("It's not a palindrome :( \n");
    }

    // n temp1 = start;
    while (start != NULL)
    {
        pop();
    }
}

int main()
{
    int c, ele, n;
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("MENU\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Palindrome\n");
        printf("5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);
        printf("\n--------------------------------------\n");
        switch (c)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &ele);
            push(ele);
            break;
        case 2:
            n = pop();
            printf("Element popped %d\n", n);
            break;
        case 3:
            display();
            break;
        case 4:
            palindrome();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Input!!!\n");
            break;
        }
    }
    return 0;
}