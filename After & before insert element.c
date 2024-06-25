#include<stdio.h>
void input_arry(int arr[],int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
}
void print_arry(int arr[],int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
}


void insert_at_position(int arr[],int size,int value,int posi)
{
    int i;
    for(i=size; i>=posi; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[posi-1]=value;
    size++;
}
void before_given_num(int arr[],int size,int v,int n_elem)
{
    int i,j,k;
    for(i=0; i<size; i++)
    {
        if(arr[i]==v)
        {
            j=i;
            break;
        }

    }
    for(k=size; k>=j; k--)
    {
        arr[k]=arr[k-1];
    }
    arr[j]=n_elem;
}


void after_given_num(int arr[],int size,int v,int n_elem)
{
    int i,j,k;
    for(i=0; i<size; i++)
    {
        if(arr[i]==v)
        {
            j=i+1;
            break;
        }

    }

    for(k=size; k>=j; k--)
    {
        arr[k]=arr[k-1];
    }
    arr[j]=n_elem;

}
int main()
{
    int arr[0],size,value,posi,v,newelement;
    printf("Enter arry size:\n");
    scanf("%d",&size);
    arr[size];
    printf("Enter arry element:\n");
    input_arry(arr,size);
    print_arry(arr,size);

    printf("\nEnter value to inserat before this value:\n");
    scanf("%d",&v);
    printf("\nEnter Newelement to inserat before of given value:\n");
    scanf("%d",&newelement);
    before_given_num(arr,size,v,newelement);
    print_arry(arr,size+1);

    printf("\nEnter value to inserat after this value:\n");
    scanf("%d",&v);
    printf("\nEnter Newelement to inserat after of given value:\n");
    scanf("%d",&newelement);
    size++;
    after_given_num(arr,size,v,newelement);
    print_arry(arr,size+1);

}


