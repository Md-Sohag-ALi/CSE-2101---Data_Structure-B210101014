

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

struct node *delete_a_specific_node(struct node *head,int pos)
{
    if(head==NULL)
    {
        printf("\nList is Empty !\n");
    }

    else if(pos == 1)
    {
        struct node *str;
        str=head;
        head=head->link;
        free(str);

    }

    else{
        struct node *ptr,*temp;
        ptr=head;
        temp=head;
        int loc=pos;
        while(loc!=1)
        {
            ptr=ptr->link;
            loc--;
        }
        loc=pos;
       while(loc !=2){
        temp=temp->link;
        loc--;
       }
        temp->link=ptr->link;
        free(ptr);
        ptr=NULL;

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

    int pos;
    printf("\nEnter position : \n");
    scanf("%d",&pos);
    head = delete_a_specific_node(head,pos);

    printf("\nNow The elements of the linked list after deleting :\n\n");
    print(head);
    return 0;
}







