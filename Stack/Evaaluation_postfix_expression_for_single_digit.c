#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define max 100
int stack_arr[max];
char postfix_arr[max];
int top = -1;
int isEmpty()
{
    if(top == -1)
        return 1;
        else
            return 0;

}

int isFull()
{
    if(top == max-1)
        return 1;
    else
        return 0;
}
void push(int oper)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
    }
    else{
            top++;
        stack_arr[top] = oper;
    }
}
int pop()
{
    if(isEmpty())
       {
           printf("Stack Underflow\n");
       }
        else{
            int value = stack_arr[top];
            top--;
            return value;
        }
}

int isSpace(char c,int i)
{
    if(postfix_arr[i] ==' ' || postfix_arr[i] =='\t' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 int  evaluate_postfix_expr()
 {
     int i,a,b;
     for(i =0;i<strlen(postfix_arr);i++)
     {
        if( !isSpace(postfix_arr[i],i))
        {
             if(postfix_arr[i] >='1' && postfix_arr[i] <='9')
        {
            push(postfix_arr[i] - '0');
         }
         else
         {
             a = pop();
             b = pop();
             switch(postfix_arr[i])
             {
             case '+' :push(b+a);break;
             case '-' : push(b-a);break;
             case '*' : push(b*a);break;
             case '/' : push(b/a);break;
             case '^' : push(pow(b,a));break;
             }
         }
        }
     }
     return pop();
 }
 int main()
 {
     printf("Enter a postfix Expression that's all character separated by a space :\n");
     gets(postfix_arr);
      int result = evaluate_postfix_expr();
      printf("%d\n",result);
      return 0;
 }
