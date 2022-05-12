#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
};

typedef struct tree *t;

t newnode(int data)
{
    t node = (t)malloc(sizeof(struct tree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

t insert(t root, int data)
{
    if (root == NULL)
    {
        root = newnode(data);
    }
    else if (root->data <= data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data > data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int check(t root1, t root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if (root1 && root2)
    {
        if ((root1->data == root2->data) && (check(root1->left, root2->left)) && (check(root1->right, root2->right)))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n, m, data, d, c, o;
    t root1 = NULL;
    t root2 = NULL;
    while (1)
    {
        printf("MENU: \n");
        printf("1. Check\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &o);
        switch (o)
        {
        case 1:
            printf("Enter the no of node in tree 1: ");
            scanf("%d", &n);
            printf("Enter the no of node in tree 2: ");
            scanf("%d", &m);
            if (n != m)
            {
                printf("Trees are not equal !!!\n");
                break;
            }
            printf("Enter the elements of tree 1: ");
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root1 = insert(root1, data);
            }
            printf("Enter the elements of tree 2: ");
            for (int i = 0; i < m; i++)
            {
                scanf("%d", &d);
                root2 = insert(root2, d);
            }
            c = check(root1, root2);
            if (c)
            {
                printf("Trees are equal\n");
            }
            else
            {
                printf("Trees are not equal\n");
            }
            break;
        case 2:
            exit(0);
        default:
            printf("Invlaid choice!!!\n");
            break;
        }
    }
    return 0;
}