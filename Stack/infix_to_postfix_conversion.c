#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char stack_arr[max];
char infix_arr[max];
char postfix_arr[max];
int top = -1;

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
        char value = stack_arr[top];
        top--;
        return value;
    }
}
char precedence(char simbol)
{
    switch(simbol)
    {
    case '^' :
        return 5;
    case '*' :
    case '/' :
        return 4;
    case '-' :
    case '+' :
        return 3;
    default :
        return 2;
    }
}

int space(char simbol)
{
    if(simbol == ' ' || simbol =='\t')
        return 1;
    else
        return 0;
}
void infixTopostfix()
{
    printf("Enter an infix expression : \n");
    gets(infix_arr);
    int i,j = 0;
    char value,simbol;
    for(i = 0; i<strlen(infix_arr); i++)
    {
    simbol = infix_arr[i];
    if( !(space(simbol)))
    {
         switch(simbol)
        {

        case '(':
            push(simbol);
            break;
        case ')':

            while((value = pop()) != '(' )
            {
                postfix_arr[j++] = value;

            }
            break;
        case '+' :
        case '-' :
        case '/' :
        case '*' :
        case '^' :
            while( !isEmpty() && precedence(stack_arr[top]) >= precedence(simbol))
            {
                postfix_arr[j++] = pop();

            }
            push(simbol);
            break;
        default :
            postfix_arr[j++] = simbol;
        }
    }

    }

    while( !isEmpty())
    {
        postfix_arr[j++] = pop();

    }
    postfix_arr[j] ='\0';

}
void print_postfix_arr()
{
    int i;
    for(i=0; i<strlen(postfix_arr);i++)
    {
        printf("%c",postfix_arr[i]);
    }
    printf("\n");
}
int main()
{
    infixTopostfix();
    print_postfix_arr();
    return 0;
}

