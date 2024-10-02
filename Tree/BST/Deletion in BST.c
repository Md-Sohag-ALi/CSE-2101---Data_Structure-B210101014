#include<stdio.h>
#include<stdlib.h>

struct node{
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

struct node *case1(struct node *root ,struct node *ptr, struct node *par)
{
    if(par ==NULL)
        root = NULL;
    else if(par->left == ptr)
        par->left =NULL;
    else
        par->right =NULL;
        free(ptr);
    return root;
};

struct node *case2(struct node*root,struct node *ptr,struct node*par)
{
    struct node *child;
    if(ptr ->left !=NULL)
        child = ptr->left;
    else if(ptr->right != NULL)
        child = ptr->right;
    if(par == NULL)
        root = child;
    else if(par ->left == ptr)
        par->left =child;
    else if(par->right == ptr)
        par->right = child;
    free(ptr);

    return root;
};
struct node*case3(struct node*root,struct node *ptr)
{
    struct node*parsuccessor,*successor;
    parsuccessor = ptr;
    successor = ptr->right;
    while(successor->left != NULL)
    {
        parsuccessor = successor;
        successor = successor->left;
    }
    ptr->data =successor->data;

    if(successor->left ==NULL && successor->right ==NULL)
       root = case1(root,successor,parsuccessor);
       else
       {
           root = case2(root,successor,parsuccessor);
       }
    return root;
};
struct node*delete_nonRec(struct node *root,int dkey)
{
    struct node*ptr,*par;
    ptr = root;
    par =NULL;
    while(ptr != NULL)
    {
        if(dkey == ptr->data)
            break;
        par =ptr;
        if(dkey < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if(ptr->left ==NULL && ptr->right ==NULL)
       root = case1(root,ptr,par);
    else if(ptr->left !=NULL &&ptr->right ==NULL || ptr->right != NULL && ptr->left ==NULL)
        root = case2(root,ptr,par);
    else
        root = case3(root,ptr);

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
    struct node *root =NULL;
    root = rec_Insert(root,50);
   root = rec_Insert(root,30);
   root = rec_Insert(root,60);
   root = rec_Insert(root,38);
   root = rec_Insert(root,35);
   root = rec_Insert(root,55);
   root = rec_Insert(root,100);
   root = rec_Insert(root,66);
   root = rec_Insert(root,88);
   root = rec_Insert(root,65);

   printf("Before Deletion \n");
   inorder(root);
   root = delete_nonRec(root,38);
   root = delete_nonRec(root,66);
   root = delete_nonRec(root,65);
   printf("\nAfter Deletion\n");
   inorder(root);

}

