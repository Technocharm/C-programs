#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int a[MAX], top = -1;

int is_full()
{
    if (top == MAX - 1)
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
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int ele)
{
    if (is_full())
    {
        printf("Stack Overflow!!!\n");
    }
    else
    {
        a[++top] = ele;
        printf("Element Inserted\n");
    }
}

int pop()
{
    if (is_empty())
    {
        printf("Stack Underflow!!!\n");
    }
    else
    {
        int ele = a[top--];
        return ele;
    }
}

void display()
{
    if (is_empty())
    {
        printf("Stack Underflow!!!\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
    }
}

void palindrome(){
    int num,n,c=0,mid,flag=0,i;
    while(top!=-1){
        pop();
    }
    printf("Enter the no: ");
    scanf("%d",&num);
    while(num){
        push(num%10);
        num=num/10;
        c++;
    }
    if(c%2==0){
        mid=c/2;
    }
    else{
        mid=(c+1)/2;
    }
    for(i=0;i<(int)mid;i++){
        if(a[i]==pop()){
            flag=1;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag){
        printf("It is a palindrome :) \n");
    }
    else{
        printf("It is not a palindrome :( \n");
    }
    while(top!=-1){
        pop();
    }
}

int main()
{
    int c,ele,n;
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
            n=pop();
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