
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
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

struct node *insert_at_a_certain_position(struct node * head,int pos,int item)
{
    struct node *temp,*ptr;
    temp=malloc(sizeof(struct node));
    temp->data=item;
    temp->link=NULL;

    ptr=head;

    if(pos==1)
    {
        temp->link=head;
        head=temp;
    }

    else
    {
        pos--;
        while(pos !=1)
        {
            ptr=ptr->link;
            pos--;
        }
        temp->link=ptr->link;
        ptr->link=temp;

    }

    return head;
}

int main()
{

    struct node *head= NULL;

      head= Add_To_Empty(head,222);
  Add_at_End(head,52);
  Add_at_End(head,92);
  Add_at_End(head,520);
  Add_at_End(head,23);
  Add_at_End(head,239);
    printf("\nThe elements of the linked list :\n");
    print(head);

    int item,pos;
    printf("\nEnter position : \n");
    scanf("%d",&pos);
    printf("\nEnter element to insert at given position :\n");
    scanf("%d",&item);
    head = insert_at_a_certain_position(head,pos,item);

    printf("\nNow The elements of the linked list :\n");
    print(head);
    return 0;
}





