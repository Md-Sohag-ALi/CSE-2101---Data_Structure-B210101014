#include<stdio.h>
int arr[10],i;
void input_Arr(){

for(i=0;i<10;i++){
    scanf("%d",&arr[i]);
}
}
void print_Arr(){

for(i=0;i<10;i++){
    printf("%d ",arr[i]);
}
}
int main(){
input_Arr();
print_Arr();
}
