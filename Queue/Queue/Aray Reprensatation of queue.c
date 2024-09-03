#include<stdio.h>
#include<stdlib.h>
#define size 100
int queue[size];
int front=-1;
int rear=-1;
int isEmpty()
{
    if(front ==-1 && rear == -1 || front ==rear + 1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(front == size -1)
      return 1;
      else
        return 0;

}

void enqueue(int data)
{
    if(isFull()){
        printf("Queue is Overflow!\n");
        exit(1);
    }
    if(front ==-1 )
        front++;

        rear++;
        queue[rear]=data;

}
int deque()
{
    int data;
    if(isEmpty())
    {
        printf("Queue is Underflow!\n");
        exit(1);
    }

    data=queue[front];
 front++;
 return data;
}
int peek()
{
    if(isEmpty())
        printf("The present queue is empty!\n");
    else
        return queue[front];
}
void print()
{
    if(isEmpty()){
          printf("Queue is Underflow!\n");
    exit(1);
    }

    else
    {
        int  i;
        for(i=front;i<=rear;i++)
        {
               printf("%d ",queue[i]);
        }
        printf("\n");
    }

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
       printf("The work is Done.\n");
       break;

   case 2:
       data = deque();
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
}
