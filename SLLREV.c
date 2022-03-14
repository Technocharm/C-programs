#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

typedef struct node * n;
n start=NULL;

n create(){
    n newnode=(n)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}

void create_list(){
    int num;
    printf("Enter the no of elements: ");
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        n newnode = create();
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
}

void reverse(){
    n curr;
    n prev;
    n next;
    prev=NULL;
    curr=start;
    while(curr!=NULL){
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
}

void display(){
    n temp=start;
    int c = 0;
    while (temp)
    {
        printf(" -> %d", temp->data);
        temp = temp->link;
        c++;
    }
    printf("\nTotal node: %d\n", c);
}

int main(){
    create_list();
    printf("--------------------\n");
    printf("before reverse: \n");
    display();
    reverse();
    printf("--------------------\n");
    printf("after reverse: \n");
    display();
    printf("--------------------\n");
    return 0;
}