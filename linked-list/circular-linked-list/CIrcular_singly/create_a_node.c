
#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node *link;
};
 struct node *create_node(struct node *tail , int data)
 {
     struct node *temp=malloc(sizeof(struct node));
     temp->data = data;
     temp->link = temp;
     tail=temp;
     return tail;
 };
 void print(struct node *tail)
{
    if(tail == NULL)
    {
        printf("List is empty !!");
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
int main()
{
    int data;
    struct node *tail = NULL;
    printf("Enter data : \n");
    scanf("%d",&data);
   tail = create_node(tail,data);
   printf("The Node is: \n");
    print(tail);

    return 0;
}
