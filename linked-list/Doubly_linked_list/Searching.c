
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

struct node *Searching(struct node *head,int item)
{
    int flag=0;
    struct node *ptr = head,*Loc=NULL;
    while(ptr != NULL)
    {
        if(ptr->data == item)
        {
            Loc=ptr;
            flag=1;
            break;
        }
        else
        {
            ptr=ptr->next;
        }
    }

    return Loc;
}

int main()
{
    struct node *head=NULL,*Loc;
    head = Create_a_doubly_linked_list(head);
    printf("\nThe elements of the linked list : \n");
    print(head);
    int item;
    printf("Enter an Element to Search : \n");
    scanf("%d",&item);

    Loc = Searching(head,item);
    if(Loc == NULL)
    {
        printf("The element isn't present in the list !!");
    }
    else
    {
        printf("The Element is Present at Location = %d\n",Loc);
    }


    return 0;
}

