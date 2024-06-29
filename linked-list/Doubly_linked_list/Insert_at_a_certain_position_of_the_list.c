

#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *Add_to_Empty_List(struct node *head,int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;

    return head;
}

void Add_at_End_of_the_List(struct node * head,int data)
{
    struct node *temp=malloc(sizeof(struct node)),*ptr;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    ptr=head;
    while(ptr ->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
    temp->prev = ptr;

}

struct node *Create_a_doubly_linked_list(struct node *head)
{
    int num_of_node,data;
    printf("Enter Number of node : \n");
    scanf("%d",&num_of_node);

    int j=1;
    printf("Enter Element for node %d :\n",j);
    scanf("%d",&data);
    head = Add_to_Empty_List(head,data);

    while(--num_of_node)
    {
        printf("Enter element for node %d :\n",j+1);
        scanf("%d",&data);
        Add_at_End_of_the_List(head,data);
        j++;
    }
    return head;
}
void print(struct node *head)
{
    struct node *ptr = head;
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

    printf("\n");
}

struct node *insert_at_a_certain_position(struct node * head,int pos,int item)
{
    struct node *temp,*ptr,*ptr2;
    temp=malloc(sizeof(struct node));
    temp ->prev = NULL;
    temp->data=item;
    temp->next=NULL;

    ptr=head;

    if(pos==1)
    {
        temp->next = ptr;
        ptr->prev = temp;
        head = temp;
    }

    else
    {
        pos--;
        while(pos !=1)
        {
            ptr=ptr->next;
            pos--;
        }
        ptr2 = ptr->next;
        ptr->next = temp;
        temp->next = ptr2;
        temp->prev = ptr;

    }

    return head;
}
int main()
{
    struct node *head=NULL;
    head = Create_a_doubly_linked_list(head);
    printf("The elements of the linked list : \n\n");
    print(head);
    int node,pos;


    printf("Enter position : \n");
    scanf("%d",&pos);
    printf("Enter node : \n");
    scanf("%d",&node);

    head = insert_at_a_certain_position(head,pos,node);
    printf("\nNow The elements of the linked list :\n");
    print(head);
    return 0;
}






