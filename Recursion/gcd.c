#include<stdio.h>
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else
        return gcd(b,a%b);
}
int main()
{
    int a,b;
    printf("Enter two number :\n");
    scanf("%d%d",&a,&b);
    int result = gcd(a,b);
    printf("The gsd of %d & %d = %d\n",a,b,result);
    return 0;
}
