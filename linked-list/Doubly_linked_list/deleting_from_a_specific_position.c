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
struct node *delete_from_a_specific_position(struct node *head,int pos)
{
    struct node *ptr = head,*temp,*temp2;

     if(head==NULL)
    {
        printf("\nList is Empty !\n");
    }
   else if(pos==1){

        struct node *temp;

        temp=head;

        head=head->next;

        free(temp);
    }
    else{

          while(pos !=1)
    {
        ptr = ptr->next;

        pos--;
    }
    ptr->prev->next = ptr->next;

    if(ptr->next != NULL)
    ptr->next->prev = ptr->prev;

    free(ptr);
    }
    return head;
}
int main()
{
    struct node *head=NULL;

    head = Create_a_doubly_linked_list(head);

    printf("The elements of the linked list : \n\n");

    print(head);

    int pos;

    printf("Enter a position : \n");

    scanf("%d",&pos);

    head = delete_from_a_specific_position(head,pos);

    printf("\nNow The elements of the linked list :\n");

    print(head);

    return 0;
}









