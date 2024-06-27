

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

struct node *delete_the_first_node(struct node *head)
{
    if(head==NULL)
    {
        printf("\nList is Empty !\n");
    }

    else{
        struct node *ptr,*temp;
        temp=head;

        head=head->link;
        free(temp);
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


    head = delete_the_first_node(head);

    printf("\nNow The elements of the linked list after deleting :\n");
    print(head);
    return 0;
}





