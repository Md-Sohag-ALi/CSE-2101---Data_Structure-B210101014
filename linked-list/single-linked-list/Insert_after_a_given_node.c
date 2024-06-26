
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


struct node *insert_after_a_given_node(struct node *head,int node,int item)
{
    int flag=0;
    struct node *temp = malloc(sizeof(struct node));
    temp->data=item;
    temp->link=NULL;

    struct node *ptr;
    ptr=head;
    while(ptr != NULL)
    {
        if(ptr->data == node)
        {
            temp->link=ptr->link;
            ptr ->link=temp;
            flag=1;
            break;
        }
        else
        {
            ptr=ptr->link;
        }

    }
    if(flag==0)
    {
        printf("The node %d is not present in the list :",node);
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

    int item,node;
    printf("\nEnter a node : \n");
    scanf("%d",&node);
    printf("Enter a element to insert after this node : \n");
    scanf("%d",&item);
    head = insert_after_a_given_node(head,node,item);

    printf("\nNow The elements of the linked list :\n\n\n");
    print(head);
    return 0;
}



