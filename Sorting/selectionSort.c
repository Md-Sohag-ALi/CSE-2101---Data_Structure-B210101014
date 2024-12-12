#include<stdio.h>
void selectionSort(int arr[],int size)
{

    int min,i,j;
    for(i=0; i<size-1; i++)
    {
        min = arr[i];
        for(j=i+1; j<size; j++)
        {
            if(arr[j]<arr[i])
            {
                min=arr[j];
                int temp =arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    }
}
int main()
{
    int i,j,size;
    printf("Enter size : \n");
    scanf("%d",&size);
    int arr[size];
    printf("Enter array element :\n");
    for(i =0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Before Shorting :\n");
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("After Shorting :\n");
    selectionSort(arr,size);
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;

}
