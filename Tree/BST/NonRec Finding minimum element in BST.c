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
    temp->left = NULL;
    temp->data = key;
    temp->right = NULL;
    return temp;
};
struct node *createBSTTree(struct node *root,int key)
{
    if(root==NULL)
        return createNode(key);
   else if(key < root->data)
        root->left =createBSTTree(root->left,key);
 else if(key > root->data)
        root->right =createBSTTree( root->right,key);
     else{
          printf("Duplicate element !\n");
     }

    return root;
};
void inorder(struct node *root)
{
    if(root ==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
struct node *minimumBST(struct node *root)
{
    if(root != NULL)
    {
        while(root->left !=NULL)
            root =root->left;
    }
    return root;
};
int main()
{
    struct node *root=NULL;
    root = createBSTTree(root,50);
    root = createBSTTree(root,40);
    root = createBSTTree(root,60);
    root = createBSTTree(root,55);
    root = createBSTTree(root,5);
    root = createBSTTree(root,0);
    printf("Inorder Traversal\n");
    inorder(root);
    struct node *temp = minimumBST(root);
    if(temp ==NULL)
        printf("Tree is Empty!\n");
    else
    printf("\nThe minimum element is = %d \n",temp->data);
    return 0;
}




