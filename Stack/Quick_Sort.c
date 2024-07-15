#include<stdio.h>
#include<stdlib.h>
void input(int arr[],int size)
{
    int i;
    for(i =0; i<size; i++)
        scanf("%d",&arr[i]);
}
void print(int arr[],int size)
{
    int i;
    for(i =0; i<size; i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int partition(int arr[],int low,int high)
{
    int i,j,pivot,pivot_index;
    pivot = arr[low];
    i = low-1;
    j = high+1;
    while(1)
    {

        do
        {
            i++;
        }
        while(arr[i]< pivot);

        do
        {
            j--;
        }
        while(arr[j] > pivot);
        if(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            pivot_index = j;
            return pivot_index;
        }

    }
}
void Quick_Sort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pivot_index = partition(arr,low,high);
        Quick_Sort(arr,low,pivot_index);
        Quick_Sort(arr,pivot_index+1,high);
    }
}
int main()
{
    int size;
    printf("Enter Number Of Elements :\n");
    scanf("%d",&size);
    int arr[size];
    input(arr,size);
    printf("Before Sorting :\n");
    print(arr,size);
    int low = 0,high = size-1;
    Quick_Sort(arr,low,high);
    printf("After Sorting :\n");
    print(arr,size);
    return 0;
}
