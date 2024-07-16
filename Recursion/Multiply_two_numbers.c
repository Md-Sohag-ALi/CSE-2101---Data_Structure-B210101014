#include<stdio.h>
int mult(int a,int b)
{
    if(b == 1)
        return a;
        else
            return a+mult(a,b-1);
}
int main()
{
    int a,b;
    printf("Enter two number :\n");
    scanf("%d%d",&a,&b);
    int result = mult(a,b);
    printf("%d * %d = %d",a,b,result);
    return 0;

}
