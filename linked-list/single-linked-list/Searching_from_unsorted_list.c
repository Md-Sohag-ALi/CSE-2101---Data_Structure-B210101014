#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *Add_To_Empty(struct node *head,int data)
{
   struct node *temp=malloc(sizeof(struct node));
   temp->data=data;
   temp->link=NULL;
   head=temp;

   return head;
}

 void Add_at_End(struct node *head,int data)
{
    struct node *temp,*ptr;
    temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr=head;
    while(ptr->link != NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void print(struct node *head)
{
    struct node *ptr=head;
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

struct node *searching_from_unsorted_list(struct node *head,int item)
{
    struct node *ptr,*loc=NULL;
    ptr=head;
    while(ptr != NULL){
        if(ptr->data == item)
        {
            loc=ptr;
            break;
        }
        else{
            ptr=ptr->link;
        }
    }
    return loc;
}
int main(){

  struct node *head= NULL;
  head= Add_To_Empty(head,222);
  Add_at_End(head,52);
  Add_at_End(head,92);
  Add_at_End(head,520);
  Add_at_End(head,23);
  Add_at_End(head,239);
  printf("\nThe elements of the linked list :\n");
  print(head);

  int item;
  printf("\nEnter a element for searching : \n");
  scanf("%d",&item);
  struct node *loc = searching_from_unsorted_list(head,item);
  if(loc==NULL){
    printf("Item Not Found\n");
  }
  else{
    printf("The item is at location= %d\n",loc);
  }

 return 0;
}


