#include<stdio.h>
#define maxSize  8
int top = -1;
int stack_arr[maxSize];

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

int peek()
{
     if(isEmpty())
    {
         printf("STACK UNDERFLOW !\n");
    }
    else{
          return stack_arr[top];
    }

}

void push()
{
    int data;
    printf("Enter element to insert onto the stack : \n");
    scanf("%d",&data);
    if(isFull())
    {
        printf("STACK OVERFLOW !\n");
        return;
    }
    else
    {
        top = top + 1;
        stack_arr[top] = data;
    }

}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow ! \n");
    }
    else
    {
        int data = stack_arr[top];
        printf("The popped value = %d\n",data);
        top = top-1 ;
    }
}

void show()
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW !\n");
        return;
    }
    else
    {
        printf("\nThe elements of the stack : \n");
        int i;
       for(i = top ;i>=0;i--)
        {
            printf("%d\n",stack_arr[i]);
        }
    }
    printf("\n");
}
int topMost()
{
    if(isEmpty())
    {
         printf("STACK UNDERFLOW ! \n");
    }
    else
    {
        printf("The top most element of the stack = %d\n",stack_arr[top]) ;
    }
}

void size(){
printf("The size of the stack = %d\n",top+1);
}

void exits()
{
   exit(0);
}

int main()
{
    int choice;
    while(1)
    {
        printf("\nYou are able to do any operation folowing : \n");
        printf("1.push() \n");
        printf("2.pop() \n");
        printf("3.isEmpty() \n");
        printf("4.isFull() \n");
        printf("5.peek() \n");
        printf("6.show() \n");
        printf("7.size() \n");
        printf("8.top() \n");
        printf("9.Exit() \n");

        printf("Enter your choice : \n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 :
                 if(isEmpty())
                printf("STACK UNDERFLOW !\n");
                else{
                    printf("STACK IS NOT EMPTY !\n");
                }
            break;
            case 4 :
                  if(isFull())
                printf("STACK OVERFLOW !\n");
                else{
                    printf("STACK IS NOT FULL !\n");
                }
            break;
            case 5 : printf("The peek value of the stack = %d\n",peek());
            break;
            case 6 : show();
            break;
            case 7 : size();
            break;
            case 8 : topMost();
            break;
            case 9 : exits();
            break;
            default: printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
