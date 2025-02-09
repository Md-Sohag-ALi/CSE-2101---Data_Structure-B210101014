#include<stdio.h>
void input_arry(int arr[],int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
}
void print_arry(int arr[],int size){
int i;
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
}
void insert_at_position(int arr[],int size,int value,int posi)
{
    int i;
for(i=size;i>=posi;i--){
    arr[i]=arr[i-1];
}
 arr[posi-1]=value;
 size++;
}
int main()
{
    int arr[0],size,value,posi;
    printf("Enter arry size:\n");
    scanf("%d",&size);
    arr[size];
    printf("Enter arry element:\n");
    input_arry(arr,size);
    print_arry(arr,size);
    printf("\nEnter element to insert any position:\n");
    scanf("%d",&value);
    printf("Enter position:\n");
      scanf("%d",&posi);
    insert_at_position(arr,size,value,posi);
     print_arry(arr,size+1);
}
