#include <stdio.h>

#define MAX_V 100 //in c it is important when we recieve a 2D array in a function

void addEdge(int adjMat[MAX_V][MAX_V], int i, int j) {
    adjMat[i][j] = 1;

    //adjMat[j][i] = 1;   this is no need for directed graph
}

void printAdjMat(int adjMat[MAX_V][MAX_V], int v) {
    for (int i = 0; i< v; i++) {
        for (int j = 0; j <v; j++) {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v, e;

    printf("Enter number of Vertices and Edges:\n");
    scanf("%d %d", &v, &e);

    int adjMat[MAX_V][MAX_V] = {0};

    for (int k = 0; k< e;k++) {
        int i, j;
        printf("Enter Edge (i -> j) one by one: \n");
        scanf("%d%d", &i, &j);
        addEdge(adjMat, i, j);
    }

    printf("Adjacency Matrix Representation:\n");
    printAdjMat(adjMat, v);

    return 0;
}

