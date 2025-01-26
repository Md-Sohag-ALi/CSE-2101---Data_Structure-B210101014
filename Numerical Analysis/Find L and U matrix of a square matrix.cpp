#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter The row or column of square matrix :\n";
    cin >> n;
    vector <vector<double>>mat(n ,vector<double>(n) );
    cout<<"Enter a "<<n<<" x "<<n<<" matrix :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n; j++)
        {
            cin >> mat[i][j];
        }
    }

  vector<vector<double>>L(n, vector<double>(n ,0)) ;
    L[0][0] = 1.0;
    L[1][1] = 1.0;
    L[2][2] = 1.0;
    double L21 = (double)mat[1][0]/mat[0][0];
    double L31 = (double)mat[2][0] /mat[0][0];
    double L32 = (double)(mat[2][1] - (mat[2][0]/mat[0][0])*mat[0][1]) / (mat[1][1] - (mat[1][0] /mat[0][0])*mat[0][1]);
    L[1][0] = L21;
    L[2][0] = L31;
    L[2][1] = L32;
    cout<<"The Lower matrix of the given matrix is :\n";
    for(int i=0; i < n ; i ++)
    {
        for(int j = 0; j < n;j ++)
        {
            cout << L[i][j] <<" ";
        }
            cout << endl;
    }
    vector<vector<double>>U(n , vector<double>(n , 0));
    double u11= mat[0][0];
    double u12 = mat[0][1];
    double u13 = mat[0][2];
    double u22 = mat[1][1] - (double)mat[0][1] *(mat[1][0]/mat[0][0]);
     double u23 = mat[1][2] - L21 *u13 ;
    double u33 = mat[2][2]-L31*mat[0][2] -L32*u23;

    U[0][0]  =  u11;
    U[0][1]  =  u12;
    U[1][2]  =  u13;
    U[1][1]  =  u22;
    U[2][2]  =  u33;
    U[1][2]  =  u23;
     cout<<"The Upper matrix of the given matrix is :\n";
    for(int i=0; i < n ; i ++)
    {
        for(int j = 0; j < n;j ++)
        {
            cout << U[i][j] <<" ";
        }
            cout << endl;
    }
    return 0;
}
