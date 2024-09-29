#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *createNode(int key)
{
    struct node *temp =malloc(sizeof(struct node));
    temp->left =NULL;
    temp->data =key;
    temp->right =NULL;
    return temp;
};
struct node *NonRec_Insert(struct node *root,int ikey)
{
    struct node*ptr,*parent,*temp;
    ptr =root;
    parent =NULL;
    while(ptr != NULL)
    {
        parent =ptr;
        if(ikey<ptr->data)
            ptr = ptr->left;
        else if(ikey>ptr->data)
            ptr = ptr->right;
        else
        {
            printf("Duplicate Key !\n");
            return root;
        }
    }
    temp = createNode(ikey);
    if(parent ==NULL)
        root =temp;
    else if(parent ->data >ikey)
        parent ->left = temp;
    else if(parent ->data < ikey)
        parent ->right = temp;

    return root;
};
void inorder(struct node*root)
{
    if(root ==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
};
int main()
{
    struct node *root = NULL;
    root = NonRec_Insert(root,50);
    root = NonRec_Insert(root,30);
    root = NonRec_Insert(root,60);
    root = NonRec_Insert(root,38);
    root = NonRec_Insert(root,35);
    root = NonRec_Insert(root,55);
    root = NonRec_Insert(root,22);
    root = NonRec_Insert(root,59);
    root = NonRec_Insert(root,80);
    root = NonRec_Insert(root,91);

    inorder(root);
    printf("\n");
    root =NonRec_Insert(root,15);
    inorder(root);
}

