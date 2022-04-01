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

int islesser(t root, int data)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->data <= data && islesser(root->left, data) && islesser(root->right, data))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isgreater(t root, int data)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->data > data && isgreater(root->left, data) && isgreater(root->right, data))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int checkbst(t root)
{
    if (root == NULL)
    {
        return 1;
    }
    if (islesser(root->left, root->data) && isgreater(root->right, root->data) && checkbst(root->left) && checkbst(root->right))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int c, n, data, m;
    t root = NULL;
    while (1)
    {
        printf("MENU\n");
        printf("1.Create\n");
        printf("2.Check if BST\n");
        printf("3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter total no of elements: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        case 2:
            m = checkbst(root);
            if (m == 1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice!!!\n");
            break;
        }
    }
    return 0;
}