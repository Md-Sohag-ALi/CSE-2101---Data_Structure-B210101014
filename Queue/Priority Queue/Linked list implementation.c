#include<stdio.h>
#include<stdlib.h>
struct node
{
    int priority;
    int data;
    struct node *link;
}*front =NULL,*rear = NULL;

int isEmpty()
{
    if(front == NULL && rear == NULL)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(int data,int priority)
{
    struct node *temp =malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("Memory is Not available!\n");
        exit(1);
    }
    temp->priority = priority;
    temp->data = data;
    temp->link = NULL;

    if(isEmpty())
    {
        front = temp;
    }
    else if(priority < front->priority)
    {
        temp->link = front;
        front = temp;
    }
    else
    {
        struct node *ptr;
        ptr = front;
        while(ptr->link != NULL && ptr->link->priority <= priority)
        {
            ptr = ptr->link;
        }
        if(ptr->link == NULL)
        {
            ptr->link = temp;
        }
        else
        {
            temp->link = ptr->link;
            ptr->link = temp;
        }


    }
}
int dequeue()
{
    if(isEmpty())
    {
         printf("Queue is Underflow!\n");
         exit(1);
    }

    struct node *temp =front;
    front =front->link;
    return temp->data;
    free(temp);
    temp =NULL;
}
void print()
{
    struct node *ptr = front;
    if(isEmpty())
    {
        printf("Queue is Underflow!\n");
        exit(1);
    }
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
void peek()
{
    if(isEmpty())
    {
        printf("Queue is Underflow!\n");
        exit(1);
    }
    printf("The first element of the Priority queue is %d\n",front->data);
}
int main()
{
    while(1)
    {
        printf("1.Insert \n");
        printf("2.Delete\n");
        printf("3.Print the first element\n");
        printf("4.Print all the elements\n");
        printf("5.Quit\n");
        int choice,data,priority;
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter element to insert:\n");
            scanf("%d",&data);
            printf("Enter priority of the element:\n");
            scanf("%d",&priority);
            enqueue(data,priority);
            break;
        case 2 :
            data = dequeue();
            printf("The deleted element is %d\n",data);
            break;
        case 3:
            peek();
            break;
        case 4 :
            print();
            break;
        case 5:
            exit(1);
            break;
        default :
            printf("Wrong Choice!\nTRY AGAIN\n");
        }
    }
    return 0;
}
