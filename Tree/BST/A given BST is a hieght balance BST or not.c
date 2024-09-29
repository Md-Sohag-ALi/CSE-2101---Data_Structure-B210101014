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

void preorder(struct node *root)
{
    if(root ==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root ==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int heightBT(struct node *root)
{
    int leftHeight,rightHieght;
    if(root == NULL)
        return 0;
    if(root->left ==NULL &&root->right ==NULL)
        return 0;
    leftHeight =heightBT(root->left);
    rightHieght =heightBT(root->right);
    if(leftHeight>rightHieght)
        return leftHeight+1;
    else
        return rightHieght+1;
}
int isBalance(struct node *root)
{
    int l=0,r=0,lh=0,rh=0,diff=0;
    if(root == NULL)
        return 1;
    l=isBalance(root->left);
    r=isBalance(root ->right);
    if(l && r)
    {
        lh=heightBT(root->left);
        rh=heightBT(root->right);
        diff = abs((lh)-(rh));
        if(diff<=1)
            return 1;
    }
    return 0;
}

int main()
{
    struct node *root=NULL;
    root = createBSTTree(root,50);
    root = createBSTTree(root,40);
    root = createBSTTree(root,60);
    root = createBSTTree(root,55);
    if(isBalance(root))
    {
        printf("Tree is height balance\n");
    }
    else
        printf("Tree is not height balance\n");

    printf("Inorder Traversal\n");
    inorder(root);

    return 0;
}
