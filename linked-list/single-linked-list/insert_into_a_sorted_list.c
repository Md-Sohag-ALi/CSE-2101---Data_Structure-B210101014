
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

struct node *insert_into_a_sorted_list(struct node * head,int item)
{
    struct node *temp,*ptr;
    temp=malloc(sizeof(struct node));
    temp->data=item;
    temp->link=NULL;

    ptr=head;
    if(head == NULL || item < head->data)
    {
        temp -> link = head;
        head=temp;
    }
    else
    {
        while(ptr->link != NULL && ptr->link->data < item)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }

    return head;
}

int main()
{

    struct node *head= NULL;

    head= Add_To_Empty(head,2);
    Add_at_End(head,5);
    Add_at_End(head,9);
    Add_at_End(head,11);
    Add_at_End(head,23);
    Add_at_End(head,34);
    printf("\nThe elements of the linked list :\n");
    print(head);

    int item;

    printf("\nEnter element to insert into sorted list :\n");
    scanf("%d",&item);
    head = insert_into_a_sorted_list(head,item);

    printf("\nNow The elements of the linked list :\n");
    print(head);
    return 0;
}




