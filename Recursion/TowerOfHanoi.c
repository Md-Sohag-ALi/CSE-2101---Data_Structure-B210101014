#include<stdio.h>
void move(int n,char A,char C,char B)
{
    if(n==1)
        printf("move from %c to %c\n",A,C);
    else
    {
        move(n-1,'A','B','C');
        move(1,'A','C','B');
        move(n-1,'C','B','A');
    }


}
int main()
{
    int n;
    printf("Enter number of disk :\n");
    scanf("%d",&n);
    move(n,'A','C','B');
    return 0;
}
