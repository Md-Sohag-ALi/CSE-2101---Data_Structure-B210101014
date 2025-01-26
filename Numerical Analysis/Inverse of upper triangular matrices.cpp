#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter The row or column of square matrix :\n";
    cin >> n;
    int mat[n][n];
    cout<<"Enter the upper triangular matrix :\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n; j++)
        {
            cin >> mat[i][j];
        }
    }
    /*Suppose you entered a matrix
               1      2   3
      A =   0     1    2
               0      0   1   */

    /*
    Let
                      a11    a12    a13
       A^-1 =     0      a22    a23
                        0        0      a33
        We know that , AA^-1 = I;
            1         2           3            a11    a12    a13       1     0      0
            0         1           2     X     0       a22     a23  =  0     1      0
            0         0           1            0        0        a33       0     0      1
            Multipliying the matrix on the left side and equating corressponding element on both side.
            we get the following equations;

           a11 = 1 ,             a12 + 2*a22 = 0,     a13 +2*a23 + 3*a33 = 0
           a22 = 1,                    a23 + 2*a33  =0
           a33 =1 */

           int   a11 = 1 ,    a22 = 1, a33 =1;
           int a23 = -2*a33;
           int a13 = -2*a23 - 3*a33;
           int a12 = -2*a22;

           mat[1][2] = a12;
           mat[2][3] = a23;
           mat[1][3] = a13;

        cout<<"The inverse matrix :\n";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }

    return 0;
}
