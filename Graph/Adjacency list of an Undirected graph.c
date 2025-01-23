#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    int weight;
    struct Node* next;
};
struct Node* createNode(int data ,int weight)
{
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> weight = weight;
    newNode -> next = NULL;
    return newNode;
};

void addEdge( struct Node* adjList[],int i,int j ,int weight)
{
    struct Node* newNode;
    newNode = createNode(j , weight);
    newNode -> next = adjList[i];
    adjList[i] = newNode;

    //this is also need as it is a undirected graph
    newNode = createNode(i , weight);
    newNode ->next = adjList[j];
    adjList[j] = newNode;

}
void printGraph(struct Node* adjList[], int v)
{
    for(int i=0; i<v; i++)
    {
        printf("%d : ",i);
        struct Node*temp = adjList[i];

        while(temp != NULL)
        {
            printf("%d(%d) ",temp->data , temp->weight);
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
    int i,j,weight;
    for(int k=0; k<e; k++)
    {

        printf("Enter the edge( i , j , weight : \n");
        scanf("%d%d%d",&i,&j,&weight);
        addEdge(adjList, i, j, weight);
    }

    printf("Adjacency List Representation:\n");
    printGraph(adjList,v);
    return 0;
}
