
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

struct node *Deleting_the_node_following_a_given_node(struct node *head,int node)
{
    if(head==NULL)
    {
        printf("\nDelete is not possible beacuse need at least two node!\n");
    }

    else if(head ->link ==NULL)
    {
        printf("\nDelete is not possible beacuse need at least two node!\n");
    }

    else
    {
        struct node *ptr,*temp1,*temp2;
        ptr=head;
        while(ptr != NULL)
        {
            if(ptr->data == node)
            {
                temp1=ptr->link;
                temp2 =ptr->link->link;
                ptr->link = temp2;
                free(temp1);
                break;
            }

            else
            {
                ptr=ptr->link;
            }

        }
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

    int node;
    printf("\nEnter a Node : \n");
    scanf("%d",&node);
    head = Deleting_the_node_following_a_given_node(head,node);

    printf("\nNow The elements of the linked list after deleting :\n\n");
    print(head);
    return 0;
}








