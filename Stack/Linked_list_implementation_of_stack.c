#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
} *top = NULL;
int isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void peek()
{
    if(isEmpty())
    {
        printf("stack Underflow !\n");
    }
    else{
        printf("The peek value of the list = %d\n",top->data);
    }
}

void push()
{
    int data;
    printf("Enter element to push onto the stack : \n");
    scanf("%d",&data);

    struct node *temp = malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Stack Overflow !\n");
        exit(1);
    }
    temp->data = data;
    temp->link = NULL;

    temp->link = top;
    top = temp;
}

int pop()
{
    struct node *temp;
    if(isEmpty()){
        printf("Stack Underflow !\n");
        exit(1);
    }
    temp = top;
    int val = top->data;
    top = top->link;
    free(temp);
    temp = NULL;
    return val;
}
void show()
{
    if(isEmpty())
    {
        printf("Stack is Empty !\n");
        exit(1);
    }

    struct node *temp;
    printf("The Stack Elements are : \n");
    temp = top;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void Exit()
{
    exit(1);
}

int main()
{
    while(1)
    {
          printf("\nYou are able to do any following operations : \n");
    printf("1. push()\n2. pop()\n3. show()\n4. Exit()\n");
    printf("Enter Your Choice : \n");
    int choice;
    scanf("%d",&choice);

    switch(choice)
    {
        case 1 : push();
        break;
        case 2 : printf("The popped value = %d",pop());
        break;
        case 3 : show();
        break;
        case 4 : Exit();
        break;
        default : printf("Invalid Choice !please try again.\n");
    }
    }

    return 0;
}

