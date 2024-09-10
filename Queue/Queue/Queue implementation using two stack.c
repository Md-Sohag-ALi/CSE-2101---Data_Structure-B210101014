#include<stdio.h>
#include<stdlib.h>
#define size 7
int top1=-1;
int top2=-1;
int stack1[size];
int stack2[size];
void peek()
{
    if(top1==-1 && top2==-1)
    {
        printf("Queue is Underflow!\n");
        exit(1);
    }
   else if(top2 !=-1)
        printf("The first element of the queue is %d\n",stack2[top2]);
    else if(top2 ==-1)
    {
         printf("The first element of the queue is %d\n",stack1[0]);
    }
}
void push1(int data)
{
    if(top1 == size-1)
    {
        printf("Queue is Overflow!\n");
        exit(1);
    }
    top1= top1+1;
    stack1[top1]=data;
}
void push2(int data)
{
    if(top2==size-1)
    {
        printf("Queue is Overflow!\n");
        exit(1);
    }
    top2++;
    stack2[top2] = data;
}
void enqueue(int data)
{
    push1(data);
}
int pop2()
{
    int data =stack2[top2];
    top2=top2-1;
    return data;
}
int pop1()
{
    int data =stack1[top1];
    top1=top1-1;
    return data;
}
int deque()
{
    if(top2==-1)
    {
        if(top1==-1)
        {
            printf("Queue is Underflow!\n");
            exit(1);
        }
        while(top1 !=-1)
        {
            int temp =pop1();
            push2(temp);
        }
    }
    int x=pop2();
    return x;
}
void print()
{
    if(top1==-1 && top2==-1)
    {
         printf("Queue is Empty!\n");
         exit(1);
    }
    int i;
    for(i=top2;i>=0;i--)
    {
        printf("%d ",stack2[i]);
    }
    for(i=0;i<=top1;i++)
    {
        printf("%d ",stack1[i]);
    }
    printf("\n");
}
int main()
{
     while(1)
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Print the first element\n");
        printf("4.Print all the elements\n");
        printf("5.Quit\n");
        int choice,data;
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter an element to be insert\n");
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            data=deque();
            printf("The deleted element is %d\n",data);
            break;
        case 3:
            peek();
             break;
        case 4:
            printf("Queue [] =");
            print();
             break;
        case 5:
            exit(1);
             break;
        default :
            printf("Wrong choice!\nTRY AGAIN\n");
        }
    }
    return 0;
}
