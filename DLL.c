#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *n;
n start = NULL;

n create()
{
    n newnode = (n)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void display()
{
    int c = 0;
    n temp = start;
    while (temp)
    {
        printf(" -> %d", temp->data);
        temp = temp->right;
        c++;
    }
    printf("\nTotal: %d\n", c);
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
            n temp = start;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = newnode;
            newnode->left = temp;
        }
    }
    printf("\n--------------------------------------\n");
    display();
    printf("\n--------------------------------------\n");
}

void insertfront()
{
    n newnode = create();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->right = start;
        start->left = newnode;
        start = newnode;
    }
    printf("\n--------------------------------------\n");
    display();
    printf("\n--------------------------------------\n");
}

void insertend()
{
    n newnode = create();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        n temp = start;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = newnode;
        newnode->left = temp;
    }
    printf("\n--------------------------------------\n");
    display();
    printf("\n--------------------------------------\n");
}

void insertpos()
{
    int pos, i = 1;
    printf("Enter the pos: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insertfront();
    }
    else
    {
        n newnode = create();
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            n temp = start;
            while (temp->right != NULL && (i <= pos - 1))
            {
                temp = temp->right;
                i++;
            }
            newnode->right = temp->right;
            newnode->left = temp;
            temp->right = newnode;
        }
        printf("\n--------------------------------------\n");
        display();
        printf("\n--------------------------------------\n");
    }
}

void deletefront()
{
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else if (start->right == NULL)
    {
        start = NULL;
    }
    else
    {
        n temp = start;
        start = temp->right;
        start->left = NULL;
    }
    printf("\n--------------------------------------\n");
    display();
    printf("\n--------------------------------------\n");
}

void deleteend()
{
    if (start == NULL)
    {
        printf("Empty\n");
    }
    else if (start->right == NULL)
    {
        start = NULL;
    }
    else
    {
        n temp = start;
        n prev;
        while (temp->right != NULL)
        {
            prev = temp;
            temp = temp->right;
        }
        free(temp);
        prev->right = NULL;
    }
    printf("\n--------------------------------------\n");
    display();
    printf("\n--------------------------------------\n");
}

void deletepos()
{
    int pos, i = 1;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        deletefront();
    }
    else
    {
        if (start == NULL)
        {
            printf("Empty\n");
        }
        else if (start->right == NULL)
        {
            start = NULL;
        }
        else
        {
            n temp = start;
            n prev;
            printf("%d%d",temp->right!=NULL,i<pos);
            while (temp->right && (i < pos))
            {
                prev = temp;
                temp = temp->right;
                i++;
                printf("%d",i);
            }
            prev->right = temp->right;
            temp->right->left = prev;
            free(temp);
        }
        printf("\n--------------------------------------\n");
        display();
        printf("\n--------------------------------------\n");
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("Menu\n");
        printf("1.Create\n");
        printf("2.Insertion at front\n");
        printf("3.Insertion at end\n");
        printf("4.Insertion at pos\n");
        printf("5.Deletion from front\n");
        printf("6.Deletion from end\n");
        printf("7.Deletion from pos\n");
        printf("8.Display\n");
        printf("9.Exit\n");
        printf("\n--------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create_list();
            break;
        case 2:
            insertfront();
            break;
        case 3:
            insertend();
            break;
        case 4:
            insertpos();
            break;
        case 5:
            deletefront();
            break;
        case 6:
            deleteend();
            break;
        case 7:
            deletepos();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid Choice!!!\n");
            break;
        }
    }
    return 0;
}
