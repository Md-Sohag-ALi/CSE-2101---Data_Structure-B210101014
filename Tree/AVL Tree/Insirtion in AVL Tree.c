#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
    int height;
};
struct node *createNode(int key)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->left = NULL;
    temp->data = key;
    temp->right = NULL;
    temp->height = 0;
    return temp;
};
int height(struct node*n)
{
    if(n == NULL)
        return -1;
    else
        return n->height;
}
int getBalanceF(struct node*n)
{
    if(n==NULL)
        return 0;
    else
        return ((height(n->left)+1)-(height(n->right)+1));
}
int max(int a,int b)
{
    return  a > b ? a : b;
}

struct node*leftRotate(struct node *A)
{
    struct node *B = A->right;
    A->right = B->left;
    B->left = A;

    A->height = 1+ max(height(A->left),height(A->right));
    B->height = 1+ max(height(B->left),height(B->right));
    return B;
};
struct node *rightRotate(struct node*B)
{
    struct node*A = B->left;
    B->left = A->right;
    A->right = B;
    B->height = 1+ max(height(B->left),height(B->right));
    A->height = 1+ max(height(A->left),height(A->right));

    return A;
};
struct node *balance(struct node *n,int BF,int key)
{
    if(BF>1)
    {
        if(key > n->left->data)
            n->left = leftRotate(n->left);
        return rightRotate(n);
    }
    else if(BF<-1)
    {
        if(n->right->data >key)
            n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
};
struct node *rec_insert(struct node *root,int key)
{
    if(root == NULL)
        root = createNode(key);
    else if(key <root->data)
        root->left = rec_insert(root->left,key);
    else if(key>root->data)
        root->right = rec_insert(root->right,key);
    else
        return root;//duplicate node

    root->height = 1+ max(height(root->left),height(root->right));
    int BF= getBalanceF(root);

    return balance(root,BF,key);
};
void inorder(struct node *root)
{
    if(root ==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
     inorder(root->right);
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
    struct node *root = NULL;
    root = rec_insert(root,1);
    root = rec_insert(root,2);
    root = rec_insert(root,3);
    root = rec_insert(root,4);
    root = rec_insert(root,5);
    root = rec_insert(root,6);
    root = rec_insert(root,7);

    inorder(root);

    if(isBalance(root))
        printf("\nThe tree is stil Balance\n");
    else
        printf("Losed the property of AVL tree\n");

    return 0;
}
