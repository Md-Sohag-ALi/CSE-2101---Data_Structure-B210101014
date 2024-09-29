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
          return root;
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
struct node*maximumBST(struct node*root)
{
    if(root !=NULL)
    {
        while(root->right != NULL)
            root = root ->right;
    }
    return root;
};
int main()
{
    struct node *root=NULL;
    root = createBSTTree(root,50);
    root = createBSTTree(root,100);
    root = createBSTTree(root,60);
    root = createBSTTree(root,55);
    root = createBSTTree(root,55);
    root = createBSTTree(root,0);

    printf("Inorder Traversal\n");
    inorder(root);

    struct node *temp = maximumBST(root);
 if(temp ==NULL)
    printf("Tree is empty!\n");
 else
    printf("\nThe maximum element is = %d \n",temp->data);
    return 0;
}






