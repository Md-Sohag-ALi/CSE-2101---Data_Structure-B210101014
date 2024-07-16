#include<stdio.h>
int fibo(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    else
        return fibo(n-2)+fibo(n-1);
}
int main()
{
    int n;
    printf("Enter how many term you want of fibonakki series : \n");
    scanf("%d",&n);
    int i=0;
    while(n--)
    {
        int result = fibo(i);
        printf("%d ",result);
        i++;
    }

    return 0;
}
