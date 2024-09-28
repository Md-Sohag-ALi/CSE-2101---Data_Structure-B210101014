#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    char data ;
    struct node*right;
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
struct node* constructBT(char InArr[],char PostArr[],int inStart,int inEnd,int *postIndex)
{
    if(inStart>inEnd)
        return NULL;
    struct node*temp =createNode(PostArr[*postIndex]);
    (*postIndex)--;
    if(inStart == inEnd)
        return temp;
    int inIndex =searchIn(InArr,inStart,inEnd,temp->data);
    temp->right = constructBT(InArr,PostArr,inIndex+1,inEnd, postIndex);
    temp->left = constructBT(InArr,PostArr,inStart,inIndex-1, postIndex);
    return temp;
};
struct node *helper(char InArr[],char PostArr[],int lenght)
{
    int postIndex =lenght;
    return  constructBT(InArr,PostArr,0,lenght,&postIndex);
};
void preorder(struct node *root)
{
    if(root ==NULL)
        return;
    printf("%c ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if(root ==NULL)
        return;
    inorder(root->left);
    printf("%c ",root->data);
   inorder(root->right);
}
void postorder(struct node *root)
{
    if(root ==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}
int main()
{
    struct node*root=NULL;
    char postArr[]={'D','E','B','F','C','A'};
    char InArr[]= {'D','B','E','A','F','C'};
    int lenght =sizeof(InArr)/sizeof(InArr[0]);
    root = helper(InArr,postArr,lenght-1);//because a static variable can not initialize a variable
    printf("Preorder\n");
    preorder(root);
      printf("\nInorder\n");
    inorder(root);
      printf("\nPostorder\n");
    postorder(root);
    return 0;
}
