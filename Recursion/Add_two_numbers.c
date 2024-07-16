#include<stdio.h>
int add(int a,int b)
{
    if(b == 0)
        return a;
    else
        return 1+add(a,b-1);
}
int main()
{
    int a,b;
    printf("Enetr two numbers :\n");
    scanf("%d%d",&a,&b);
    int result = add(a,b);
    printf("%d\n",result);
    return 0;
}
