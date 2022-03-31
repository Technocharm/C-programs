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

int search(t root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == data)
    {
        return 1;
    }
    else if (data <= root->data)
    {
        search(root->left, data);
    }
    else if (data > root->data)
    {
        search(root->right, data);
    }
}

void preorder(t root)
{
    if (root)
    {
        printf("-> %d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(t root)
{
    if (root)
    {
        inorder(root->left);
        printf("-> %d", root->data);
        inorder(root->right);
    }
}

void postorder(t root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("-> %d", root->data);
    }
}

int main()
{
    int data, num, n, c;
    t root = NULL;
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("MENU\n");
        printf("1.Create\n");
        printf("2.Search\n");
        printf("3.Preorder\n");
        printf("4.Inorder\n");
        printf("5.Postorder\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        printf("\n--------------------------------------\n");
        switch (c)
        {
        case 1:
            printf("Enter the no of elements to be inserted: ");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        case 2:
            printf("Enter element to be searched ");
            scanf("%d", &n);
            if (search(root, n))
            {
                printf("Element found!!!");
            }
            else
            {
                printf("Element not found!!!");
            }
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Input!!!");
        }
    }
}