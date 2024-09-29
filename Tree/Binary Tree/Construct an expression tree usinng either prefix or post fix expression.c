#include<stdio.h>
#include<stdlib.h>
#define maxSize 100
struct node
{
    struct node*left;
    char data;
    struct node *right;
};
int top = -1;
struct node*stack[maxSize];
int isEmpty()
{
    if(top  == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if(top == maxSize - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct node *data)
{

    if(isFull())
    {
        printf("STACK OVERFLOW !\n");
        return;
    }
    else
    {
        top = top + 1;
        stack[top] = data;
    }

}
struct node* pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow ! \n");
    }
    else
    {
        struct node* data = stack[top];
        top = top-1 ;
        return data;
    }
}
struct node*createNode(char data)
{
    struct node*temp =malloc(sizeof(struct node));
    temp->left = NULL;
    temp->data = data;
    temp->right = NULL;
    return temp;
};
struct node*expressionTree(char postfix[])
{
    int i=0;
while(postfix[i] != '\0')
{
     struct node*temp;
    char symbol =postfix[i];
    if(symbol>='a' && symbol<='z')
    {
      temp =createNode(symbol);
       push(temp);
    }
    else{
        struct node *A, *B;
         temp =createNode(symbol);
        A=pop();
        B=pop();
        temp->left=B;
        temp->right =A;
        push(temp);
    }
    i++;
}
 return pop();
};
void postorder(struct node *root)
{
  if(root ==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
      printf("%c ",root->data);
}
int main()
{
    struct node *root;
    char postfix[] = {'a','b','c','*','d','e','f','/','+','/'};
   root = expressionTree(postfix);
    printf("Postorder\n");
    postorder(root);
        return 0;
}
