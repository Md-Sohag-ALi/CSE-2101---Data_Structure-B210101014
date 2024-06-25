#include<stdio.h>

void input(int arr[],int size){
int i;
for(i=0;i<size;i++)
{
    scanf("%d",&arr[i]);
}
}

int search(int arr[],int size,int value){
int i;
for(i=0;i<size;i++){
  if(arr[i]==value){

   printf("\nThe value %d found at position %d\n",value,i+1);

     //break;
  }

}
if(i==size)
    printf("The value %d not found!",value);
}

int main()
{
    int arr[0],i,size,value;
    printf("Enter size:\n");
     scanf("%d",&size);
     arr[size];
     printf("Enter arry element:\n");
    input(arr,size);
    printf("Enter a element:\n");
     scanf("%d",&value);
    search(arr,size,value);
}
