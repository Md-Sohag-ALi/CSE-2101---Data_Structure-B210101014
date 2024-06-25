#include<stdio.h>
int binary_search(int a[],int n,int item)
{
    int mid,lb=0,ub=n-1;

    while(lb<=ub)
    {
        mid=(ub+lb)/2;
        if(a[mid]==item)
        {
            return mid;
        }
        else if(a[mid]>item)
        {
            ub=mid-1;
        }
        else
        {
            lb=mid+1;
        }
    }
    return -1;
}
int main()
{
    int a[1000],n,i,item;
    printf("Enter array size:\n");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter item to search:\n");
    scanf("%d",&item);
    int res=binary_search(a,n,item);
    if(res>=0){
        printf("index = %d\n",res);
    }
    else{
        printf("Not found\n");
    }

}
