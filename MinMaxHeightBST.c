#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
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
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

int maxele(t root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int minele(t root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int height(t root)
{
    int h = 0, l = 0, r = 0;
    if (root == NULL)
    {
        return -1;
    }
    l = height(root->left);
    r = height(root->right);
    if (l > r)
    {
        h = l;
    }
    else
    {
        h = r;
    }
    return h + 1;
}

int main()
{
    int c, n, data, m;
    t root = NULL;
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("MENU\n");
        printf("1.Create\n");
        printf("2.Min Element\n");
        printf("3.Max Element\n");
        printf("4.Height of tree\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        printf("\n--------------------------------------\n");
        switch (c)
        {
        case 1:
            printf("Enter the no of elements: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        case 2:
            m = minele(root);
            if (m == -1)
            {
                printf("Empty!!!\n");
            }
            else
            {
                printf("Min Element = %d\n", m);
            }
            break;
        case 3:
            m = maxele(root);
            if (m == -1)
            {
                printf("Empty!!!\n");
            }
            else
            {
                printf("Max Element = %d\n", m);
            }
            break;
        case 4:
            m = height(root);
            if (m == -1)
            {
                printf("Empty!!!\n");
            }
            else
            {
                printf("Height of tree = %d\n", m);
            }
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!!!\n");
            break;
        }
    }
    return 0;
}