#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link ;
}*front = NULL,*rear = NULL;
int isEmpty()
{
    if(front==NULL)
    return 1;
    else
        return 0;
}
int enqueue(int data)
{
    struct node *temp;
    temp= malloc(sizeof(struct node));
    if(temp == NULL){
         printf("Memory doesn't exceed!\n");
         exit(1);
    }
    temp->data = data;
    temp->link = NULL;

    if(rear ==NULL)
    {
        rear =front=temp;
    }
    else{
        rear->link = temp;
        rear = temp;
    }
}
int dequeue()
{
    int data;
    if(isEmpty())
        printf("Queue is empty!\n");
    struct node *temp=malloc(sizeof(struct node));
    if(temp ==NULL)
        printf("Memory doesn't exceed!\n");
    temp =front;
    data=temp->data;
    front =front->link;
    free(temp);
    temp=NULL;
}
int peek()
{
    int data;
    if(isEmpty())
        printf("Current Queue is Empty!\n");
    data = front->data;
    return data;
}
void print()
{
    struct  node *ptr;
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    ptr = front;
    printf("%d",ptr->data);
    ptr=front->link;
    while(ptr !=NULL)
    {
        printf("->%d",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
int main()
{

    int choice,data;
  while(1)
  {
       printf("1.Insert\n");
   printf("2.Delete\n");
   printf("3.Print the first element\n");
   printf("4.print all the  elements\n");
   printf("5.Quit\n");
   printf("Enter your choice : \n");
   scanf("%d",&choice);
   switch(choice){
   case 1:
       printf("Enter Element tobe added in the queue :\n");
       scanf("%d",&data);
       enqueue(data);
       printf("Succesfull.\n");
       break;

   case 2:
       data = dequeue();
       printf("The Deleted data is %d\n",data);
       break;
    case 3:
       data = peek();
       printf("The First element of the queue is %d\n",data);
       break;
   case 4:
       printf("Queue[]= ");
        print();
        break;
   default :
    exit(1);
   }
  }
    return 0;
}
