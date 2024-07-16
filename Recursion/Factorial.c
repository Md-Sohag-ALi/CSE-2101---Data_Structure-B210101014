#include<stdio.h>
long long int factorial(long long int n)
{
    if(n == 1 || n ==0)
        return 1;
    else
        return n*factorial(n-1);
}
int main()
{
  long long  int n;
    printf("Enter a Number :\n");
    scanf("%lld",&n);
    long long int result = factorial(n);
    printf("%lld! = %lld\n",n,result);
    return 0;
}
