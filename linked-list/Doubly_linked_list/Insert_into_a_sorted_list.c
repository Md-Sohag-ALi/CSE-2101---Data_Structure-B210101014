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

    head = Add_to_Empty_List(head,data);//

    num_of_node -=1;

    while(num_of_node--)
    {
        j++;

        printf("Enter element for node %d :\n",j);

        scanf("%d",&data);

      Add_at_End_of_the_List(head,data);
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
struct node *insert_into_a_sorted_list(struct node *head,int item)
{
    struct node *temp,*ptr;

    temp=malloc(sizeof(struct node));

    temp->prev= NULL;

    temp->data=item;

    temp->next=NULL;

    if(head == NULL || item < head->data)
    {
        ptr=head;

        temp->next = ptr;

        ptr->prev = temp;

        head = temp;
    }
    else
    {
        ptr=head;

        while(ptr->next != NULL && ptr->next->data < item)
        {
            ptr=ptr->next;
        }
        temp->next = ptr->next;

        temp->prev = ptr;

        ptr->next = temp;
    }

    return head;
}
int main()
{
    struct node *head=NULL;

    head = Create_a_doubly_linked_list(head);

    printf("The elements of the linked list : \n\n");

    print(head);

    int item;

    printf("\nEnter element to insert into sorted list :\n");

    scanf("%d",&item);

    head = insert_into_a_sorted_list(head,item);

    printf("\nNow The elements of the linked list :\n");

    print(head);

    return 0;
}







