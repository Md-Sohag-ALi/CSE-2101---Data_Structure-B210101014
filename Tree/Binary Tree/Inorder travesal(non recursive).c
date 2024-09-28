#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node* stack[MAX];
int top =-1;
int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
void push(struct node *ptr)
{
    if(top == MAX-1)
    {
        printf("Stack Overflow!\n");
        exit(1);
    }
    top++;
    stack[top] = ptr;
}
struct node* pop()
{
    struct node*ptr;
    if(top==-1)
    {
        printf("Stack Underflow!\n");
        exit(1);
    }
    ptr = stack[top];
    top--;
    return ptr;
}

struct node *createTree()
{
    int add;
    printf("Do you want to add a node(0 for no 1 for yes) :");
    scanf("%d",&add);
    if(!add)
    {
        return NULL;
    }
    else
    {
        struct node *temp=malloc(sizeof(struct node));
        int data;
        printf("Enter the data :");
        scanf("%d",&data);
        temp->data=data;
        printf("As The left child of %d\n",temp->data);
        temp->left= createTree();
        printf("As Right child of %d\n",temp->data);
        temp->right=createTree();
        return temp;
    }
};

void inorder(struct node *root)
{
       struct node*ptr = root;
    while(1)
    {
        while(ptr->left !=NULL)
        {
            push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right ==NULL)
        {
            printf("%d ",ptr->data);
            if(isEmpty())
                return;
            ptr=pop();
            printf("%d ",ptr->data);
            ptr =ptr->right;
        }
    }
}
int main()
{
    struct node *root;
    root =createTree();
    inorder(root);
    return 0;
}
