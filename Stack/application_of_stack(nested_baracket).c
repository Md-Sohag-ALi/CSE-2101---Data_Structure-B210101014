
#include<stdio.h>
#include<stdlib.h>
#include<string.h>// for gets()
#define max 100
char stack_arr[max];
int top = -1;
int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
int mismatch_char(char a,char b)
{
    if(a =='[' && b == ']' || a == '{' && b=='}' || a == '(' && b == ')')
        {
            return 1;
        }
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
void push(char data)
{
    if(isFull())
    {
        printf("Stack Overflow!\n");
        exit(1);
    }
    else
    {
        top++;
        stack_arr[top] = data;
    }
}
char pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        int value = stack_arr[top];
        top--;
        return value;
    }
}

void check_balance(char  *str)
{
    int i;
    for(i =0 ; i<strlen(str); i++)
    {
        if(str[i] =='[' || str[i] == '{' || str[i] == '(')
        {
            push(str[i]);
        }
        if(str[i] == ']'  || str[i] == '}' || str[i] == ')')
        {
            if(isEmpty())
            {
                printf("Invalid expression !right bracket more than left.\n");
                exit(1);
            }
            else
            {
                char data = pop();
                if( !mismatch_char(data,str[i]))
                {
                    printf("Invalid expression ! Character mismatch!\n");
                    exit(1);
                }

            }

        }

    }
    if(isEmpty())
    {
        printf("Valid expression.\n");
    }
    else
        printf("Invalid expression !\n");
}
int main()
{
    char expr[max];
    printf("Enter the algebric expression :\n");
    gets(expr);
    check_balance(expr);
    return 0;
}

