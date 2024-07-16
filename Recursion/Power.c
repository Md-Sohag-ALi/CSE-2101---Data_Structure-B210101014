#include<stdio.h>
int power(int a,int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    else
        return a*power(a,b-1);
}
int main()
{
    int a,b;
    printf("Enter base and exponetial :\n");
    scanf("%d%d",&a,&b);
    int result = power(a,b);
    printf("%d^%d = %d",a,b,result);
    return 0;
}
