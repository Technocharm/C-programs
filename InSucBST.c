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

t search(t root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == data)
    {
        return root;
    }
    else if (data <= root->data)
    {
        search(root->left, data);
    }
    else if (data > root->data)
    {
        search(root->right, data);
    }
    else{
        return NULL;
    }
}

t minimum(t root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

t insucbst(t root, int data)
{
    t curr = search(root, data);
    if (curr == NULL)
    {
        return NULL;
    }
    if (curr->right != NULL)
    {
        return minimum(curr->right);
    }
    else
    {
        t succ = NULL;
        t ances = root;
        while (ances != curr)
        {
            if (curr->data < ances->data)
            {
                succ = ances;
                ances = ances->left;
            }
            else
            {
                ances = ances->right;
            }
        }
        return succ;
    }
}

int main()
{
    int c, data, n, d;
    t m;
    t root = NULL;
    while (1)
    {
        printf("\n--------------------------------------\n");
        printf("MENU\n");
        printf("1.Create\n");
        printf("2.InorderSuccessor\n");
        printf("3.Exit\n");
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
            printf("Enter the element u want inorder successor: ");
            scanf("%d", &d);
            m = insucbst(root, d);
            if(m==NULL){
                printf("No Inorder Successor Exist\n");
                break;
            }
            printf("InorderSuccessor is -> %d\n", m->data);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}