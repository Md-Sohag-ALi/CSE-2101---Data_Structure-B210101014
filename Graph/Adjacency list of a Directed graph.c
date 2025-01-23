#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
};

void addEdge( struct Node* adjList[],int i,int j)
{
    struct Node* newNode;
    newNode = createNode(j);
    newNode -> next = adjList[i];
    adjList[i] = newNode;

  //The below code no need for directed graph

//    newNode = createNode(i);
//    newNode ->next = adjList[j];
//    adjList[j] = newNode;

}
void printGraph(struct Node* adjList[], int v)
{
    for(int i=0; i<v; i++)
    {
        printf("%d : ",i);
        struct Node*temp = adjList[i];

        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp -> next;
        }
        printf("\n");
    }
}

int main()
{
    int v,e;
    printf("Enter Number of vertices and edges : \n");
    scanf("%d%d",&v,&e);
    struct Node * adjList[v];
    for(int i=0; i<v; i++)
    {
        adjList[i] = NULL;
    }
    int i,j;
    for(int k=0; k<e; k++)
    {

        printf("Enter the edge(i -> j) one by one: \n");
        scanf("%d%d",&i,&j);
        addEdge(adjList, i,j);
    }



    printf("Adjacency List Representation:\n");
    printGraph(adjList,v);
    return 0;
}

