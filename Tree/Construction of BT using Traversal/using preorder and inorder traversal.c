#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    char data;
    struct node *right;
};
struct node*createNode(char data)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->left =NULL;
    temp->data = data;
    temp->right = NULL;
    return temp;
};
int searchIn(char InArr[],int InStart,int InEnd,char data)
{
    int i;
    for(i =InStart; i<=InEnd; i++)
    {
        if(InArr[i] == data)
        {
            return i;
        }
    }
}
struct node *constructBT(char PreArr[],char InArr[],int InStart,int InEnd)
{
    if(InStart>InEnd)
        return NULL;
    static int preIndex =0;
    struct node*temp =createNode(PreArr[preIndex]);
    preIndex++;
    if(InStart==InEnd)
        return temp;
    int InIndex =searchIn(InArr,InStart,InEnd,temp->data);
    temp->left = constructBT(PreArr,InArr,InStart,InIndex-1);
    temp->right = constructBT(PreArr,InArr, InIndex + 1,InEnd);
    return temp;
};
void preorder(struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%c ",root->data);
    preorder(root->left);
    preorder(root->right);
};
void Inorder (struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%c ",root->data);
    Inorder(root->right);
}
void postorder(struct node*root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}
int main()
{
    struct node *root =NULL;
    char PreArr[]= {'A','B','D','E','C','F'};
    char InArr[]= {'D','B','E','A','F','C'};
    int lenght =sizeof(InArr)/sizeof(InArr[0]);
    root = constructBT(PreArr,InArr,0,lenght-1);
    printf("Preorder\n");
    preorder(root);
    printf("\nInorder\n");
    Inorder(root);
    printf("\nPostorder\n");
    postorder(root);
    return 0;
}
