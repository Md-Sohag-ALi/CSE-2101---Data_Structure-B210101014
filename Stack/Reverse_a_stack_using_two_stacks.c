#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int isEmpty(struct node **top)
{
    if(*top == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void push(int data,struct node **top1)
{
    struct node *temp = malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Stack Overflow !\n");
        exit(1);
    }
    temp->data = data;
    temp->link = NULL;

    temp->link = *top1;
    *top1 = temp;

}

int pop(struct node **top)
{
    struct node *temp;
    int val;
    if(isEmpty( top))
    {
        printf("Stack Underflow !\n");
        exit(1);
    }
    temp = *top;
    val = temp->data;
    *top = (*top)->link;
    free(temp);
    temp = NULL;
    return val;
}
void reverse_stack_using_two(struct node **top)
{
    struct node *top1 = NULL;
    struct node *top2= NULL;

    while(*top != NULL)
    {
        push(pop(top), &top1);
    }
    while(top1 != NULL)
    {
        push(pop(&top1), &top2);
    }
    while(top2 != NULL)
    {
        push(pop(&top2), top);
    }
}
void show(struct node **top)
{
    if(isEmpty(top))
    {
        printf("Stack is Empty !\n");
        exit(1);
    }

    struct node *temp;
    printf("The Stack Elements are : \n");
    temp = *top;
    while(temp)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    struct node *top =NULL ;
    int data,choice;
    while(1)
    {
        printf("You are able to do any following operations :\n");
        printf("1.push()\n2.print()\n3.reverse_stack()\n4.Exit()\n");
        printf("Enter your Choice : \n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be pushed :\n");
            scanf("%d",&data);
            push(data,&top);
            break;
        case 2 :
            show(&top);
            break;
        case 3:
            reverse_stack_using_two(&top);
            printf("Stack is reversed!\n");
            break;
        case 4:
            exit(1);
            break;
        default :
            printf("Invalid choice ! please try again.\n");
        }
    }
    return 0;
}


