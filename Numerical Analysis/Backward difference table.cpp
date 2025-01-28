#include<bits/stdc++.h>
using namespace std;
void BackDiffTable(vector<vector<double>>&table ,int n)
{
    for(int i = 1;i<n ;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            table[j][i] = table[j][i-1] - table[j-1][i-1];
        }
    }
}
void print(vector<vector<double>>&table ,int n, vector<double>&X)
{
    for(int i=0;i<n;i++)
    {
        cout << X[i];
        for(int j=0;j<=i;j++)
        {
            cout<<"\t"<<table[i][j];
        }
        cout <<endl;
    }
}
int main()
{
    int n;
    cout << "Enter Number of Data points :\n";
    cin >> n;
    vector<double>X(n);
    vector<double>Y(n);
    vector<vector<double>>table(n,vector<double>(n , 0));
    cout << "Enter X values :\n";
    for(int i=0;i<n;i++)
    {
        cin >>X[i];
    }

     cout << "Enter Y values :\n";
    for(int i=0;i<n;i++)
    {
        cin >>Y[i];
        table[i][0] = Y[i];
    }
     BackDiffTable(table , n);
     cout << "The Backward difference Table:\n";
     print(table ,n,X);
    return 0;
}
