#include<stdio.h>
#include<math.h>
int weighted[10][10] ,distance[10][10],vrtx;

 void floyedWrshall()
 {
     int i,j,k;
     for(k = 0;k<vrtx;k++)
     {
         for( i=0;i<vrtx;i++)
         {
             for(j=0;j< vrtx ;j++)
             {
                 if ( distance[i][k] + distance[k][j]  < distance[i][j] )
                    distance[i][j] = distance[i][k] + distance[k][j];
             }
         }
     }
 }
 void print()
 {
     int i,j;
     for(i=0;i<vrtx;i++)
     {
         for(j=0;j<vrtx;j++)
         {
             printf("%d ",distance[i][j]);
         }
         printf("\n");
     }
 }
int main()
{
    int i,j;
    printf("Enter the Number of vrtices :\n");
    scanf("%d",&vrtx);
    printf("Enter the weighted Matrix :\n");
    for( i=0;i<vrtx;i++)
    {
        for(j =0;j<vrtx ;j++)
        {
           scanf("%d",&weighted[i][j]);
            distance[i][j] = weighted[i][j];
        }
    }
    printf("Result:\n");
    floyedWrshall( );
    print();
    return 0;
}
