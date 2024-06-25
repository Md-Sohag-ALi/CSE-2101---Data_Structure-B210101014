#include<stdio.h>
void bubble_sort(int a[],int n){
int i,j;
 for(i=0;i<n;i++){
        int flag=0;
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }

        }
       if(flag==0){
            break;
        }

    }
    printf("The sorted array:\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main()
{
    int a[1000],n,i;
    printf("Enter array size:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
   bubble_sort(a,n);
}
