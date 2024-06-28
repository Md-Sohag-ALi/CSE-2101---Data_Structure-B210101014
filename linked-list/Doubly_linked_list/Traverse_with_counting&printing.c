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

void count(struct node *head)
{
    int count=0;
    struct node *ptr = head;
    while(ptr != NULL)
    {
         count++;
        ptr=ptr->next;
    }

    printf("\nThe number of element of the linked list = %d\n",count);
}
int main()
{
    struct node *head=NULL;
    head = Create_a_doubly_linked_list(head);
    printf("\nThe elements of the linked list : \n");
    print(head);
    count(head);
    return 0;
}

