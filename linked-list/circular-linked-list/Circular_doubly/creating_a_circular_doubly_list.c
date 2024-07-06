#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node * add_to_empty(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp ->prev = temp;
    temp ->next = temp;
    tail = temp;
    return tail;
};

struct node *add_at_the_end(struct node *tail,int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    struct node *ptr;
    ptr = tail->next;

    tail->next =temp;
    temp->prev = tail;
    temp->next = ptr;
    ptr->prev = temp;
    tail = tail->next;
    return tail;


};

struct node *creating_a_circular_doubly_list(struct node * tail)
{
    int i,num,data;
    printf("Enter No. of node : \n");
    scanf("%d",&num);
    if(num == 0)return tail;
    printf("Enter element for node  : 1 :\n");
    scanf("%d",&data);
    tail = add_to_empty(tail,data);

    for(i = 1; i<num; i++)
    {
        printf("Enter element for node : %d\n",i+1);
        scanf("%d",&data);
        tail = add_at_the_end(tail,data);
    }
    return tail;
}

void print(struct node *tail)
{
    struct node *ptr;
    ptr = tail->next;

    if(tail == NULL)
    {
        printf("List is empty !!\n");
    }
    else
    {
        do
        {
            printf("%d ",ptr->data);
            ptr = ptr->next;
        }
        while(ptr != tail->next);

    }
     printf("\n");
}

int main()
{
    struct node *tail =NULL;
    tail = creating_a_circular_doubly_list( tail);
    printf("The elements of the list : \n");
    print(tail);
}

