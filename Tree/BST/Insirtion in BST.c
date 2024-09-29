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
struct node *rec_Insert(struct node *root ,int key)
{
    if(root == NULL)
        return createNode(key);
    else if(root->data>key)
        root->left = rec_Insert(root->left,key);
    else if(root->data <key)
        root->right  = rec_Insert(root->right,key);
    else
        printf("\nDuolicate Key!\n");

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
   root = rec_Insert(root,50);
   root = rec_Insert(root,30);
   root = rec_Insert(root,60);
   root = rec_Insert(root,38);
   root = rec_Insert(root,35);
   root = rec_Insert(root,55);
   root = rec_Insert(root,22);
   root = rec_Insert(root,59);
   root = rec_Insert(root,80);
   root = rec_Insert(root,91);

   inorder(root);
   printf("\n");
   root = rec_Insert(root,15);
     inorder(root);
}
