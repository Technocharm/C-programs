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

t minimum(t root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

t delete (t root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            t temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            t temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            t temp = minimum(root->right);
            // printf("%d", temp->data);
            root->data = temp->data;
            root->right = delete (root->right, temp->data);
        }
    }
    return root;
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

int main()
{
    int c, data, n, ele;
    t root = NULL;
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("MENU\n");
        printf("1.Create\n");
        printf("2.Delete a node\n");
        printf("3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        printf("\n--------------------------------------\n");
        switch (c)
        {
        case 1:
            printf("Enter the no of ele: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root = insert(root, data);
            }
            break;
        case 2:
            printf("Enter the ele to be deleted: ");
            scanf("%d", &ele);
            printf("Before delete: \n");
            inorder(root);
            delete (root, ele);
            printf("\nAfter delete: \n");
            inorder(root);
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