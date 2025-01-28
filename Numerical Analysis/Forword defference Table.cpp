#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<double>>&table,int n,vector<double>&X)
{
    for(int i =0;i<n;i++)
    {
        cout<<X[i];
        for(int j=0;j<n-i;j++)
        {
            cout<<"\t"<<table[i][j];
        }
        cout<<endl;
    }
}
void forDiffTable(vector<vector<double>>&table,int n)
{
    for(int i=1;i< n;i++)
    {
        for(int j=0 ;j<n-1;j++)
        {
            table[j][i] = table[j+1][i-1] - table[j][i-1];
        }
    }
}
int main()
{
 int n;
 cout<<"Enter Number of data points :\n";
 cin>>n;
vector<double>X(n);
vector<double>Y(n);
vector<vector<double>>table(n,vector<double>(n));
cout<<"Enter The X Values :\n";
for(int i=0;i<n;i++)
{
    cin>>X[i];
}
cout<<"Enter The Y Values :\n";
for(int i= 0;i<n;i++)
{
    cin>>Y[i];
    table[i][0] = Y[i];
}
forDiffTable(table,n);
cout << "Forward Difference Table :\n";
print(table , n,X);
    return 0;
}
