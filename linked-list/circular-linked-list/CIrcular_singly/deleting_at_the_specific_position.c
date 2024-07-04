
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *add_to_empty(struct node *tail,int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = temp;
    tail = temp;
    return tail;
}
struct node *add_to_the_end(struct node * tail,int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = tail ->link;
    tail->link = temp;
    tail = tail->link;
    return tail;
}

struct node * create_circular_singly_list(struct node *tail )
{
    int num,i,data;
    printf("Enter Number of Node : \n");
    scanf("%d",&num);
    if(num ==  0)
        return tail;
    printf("Enter element for node : 1 \n");
    scanf("%d",&data);
    tail = add_to_empty(tail,data);
    for(i=1;i<num;i++)
    {
        printf("Enter element for node : %d\n",i+1);
        scanf("%d",&data);
       tail = add_to_the_end(tail,data);
    }
    return tail;
}
void print(struct node *tail)
{
    if(tail == NULL)
    {
        printf("List is empty !!\n");
    }
    else
    {
        struct node *ptr=tail->link;
        do
        {
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
        while(ptr != tail->link);
    }

    printf("\n");
}

struct node *delete_at_specific_position(struct node *tail,int pos)
{
    struct node *ptr,*ptr2;
    ptr =tail->link;

    if(tail == NULL){
    return tail;
    }

    if(tail->link == tail){
        free(tail);tail=NULL;
        return tail;
    }
    if(pos == 1)
    {
      tail->link = ptr ->link;
      free(ptr);
      return tail;
    }
    while(pos !=2)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2 = ptr->link;
    ptr->link = ptr2->link;
    if(ptr2 == tail)
    tail = ptr;
    free(ptr2);
    return tail;
};
int main()
{
    struct node *tail = NULL;

    tail = create_circular_singly_list(tail);
     printf("The Elements of the list : \n");
    print(tail);

    int data , pos ;
    printf("Enter position : \n");
    scanf("%d",&pos);
    tail = delete_at_specific_position(tail,pos);
    printf("Now the elements of the list : \n");
    print(tail);
    return 0;
}
