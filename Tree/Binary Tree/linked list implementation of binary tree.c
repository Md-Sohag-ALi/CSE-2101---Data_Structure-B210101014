#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *createTree()
{
    int add;
    printf("Do you want to add a node(0 for no 1 for yes) :");
    scanf("%d",&add);
    if(!add)
    {
        return NULL;
    }
    else
    {
        struct node *temp=malloc(sizeof(struct node));
        int data;
        printf("Enter the data :");
        scanf("%d",&data);
        temp->data=data;
        printf("As The left child of %d\n",temp->data);
        temp->left= createTree();
        printf("As Right child of %d\n",temp->data);
        temp->right=createTree();
        return temp;
    }
};
int main()
{
    struct node *root;
    root =createTree();
    while(root->left != NULL)
        printf("%d\n",root->data);
    printf("%d ",root->data);
    printf("%d ",root->left->data);
    printf("%d ",root->right->data);
    printf("%d ",root->left->left->data);
    return 0;
}