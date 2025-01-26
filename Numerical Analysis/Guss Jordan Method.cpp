
#include<bits/stdc++.h>
using namespace std;
void print(double mat[10][10] ,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            cout<< mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void GussianElimination(double mat[][10],int n)
{
    double ratio ;
    for(int i =1 ; i <= n-1 ; i++) //joto gula eq. tar theke 1 kom
    {
        for(int j = i +1 ; j <= n; j++)
        {
            ratio = mat[j][i] /mat[i][i];
            for(int k=1 ; k <=n+1; k++)
            {
                mat[j][k] = mat[j][k] - ratio*mat[i][k];
            }
        }
    }
      cout << "After Gussian Elimination  :\n";
     print(mat ,n);
    // Solution Finding
    // Back Substitution
    vector<double> solution(n + 1);

    for (int i = 1; i <= n; i++)
    {
       solution[i] = mat[i][n+1] /mat[i][i];
    }
    cout<<"The Solution are :\n";
    for(int i=1;i<=n;i++)
    {
            cout << "x"<< i<< " = "<< fixed << setprecision(2) << solution[i]<<endl;
    }
}
int main()
{
    int n;
    cout << "Enter Number of Unkowns in the System :\n";
    cin >> n;
    double mat[10][10];
    //OR
    //vector<vector<double>>mat(n +1 ,vector<double>(n+2));
    cout << "Enter Augmented Matrix :\n";
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= n+1; j++)
        {
            cin>>mat[i][j];
        }
    }
    cout <<"Entered Augmented Matrix :\n";
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <= n+1; j++)
        {
            cout << mat[i][j] <<" ";
        }
        cout << endl;
    }
    GussianElimination( mat,n);
    return 0;
}
