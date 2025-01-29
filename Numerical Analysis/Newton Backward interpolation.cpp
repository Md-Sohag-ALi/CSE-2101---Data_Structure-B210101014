#include<bits/stdc++.h>
using namespace std;
void backWardDiff(vector<vector<double>>&table ,int n)
{
    for(int i=1;i < n; i++ )
    {
        for(int j=n-1;j >= i ;j--)
        {
            table[j][i] = table[j][i-1] -table[j-1][i-1];
        }
    }
}
void print (vector<vector<double>>&table , int n,vector<double>&X)
{
      for(int i=0;i < n; i++ )
    {
        cout << X[i];
        for(int j=0;j <= i ; j++)
        {
          cout <<"\t"<< table[i][j];
        }
        cout<<endl;
    }
}
double fact(int e)
{
    double fact = 1.0;
    for(int i =2 ;i<=e;i++)
    {
        fact *=i;
    }
    return fact;
}
double newtonBackwardDiffInter(vector<vector<double>>&table ,vector<double>&X,int n , double x)
{
    double h = X[1]-X[0];
    double p = (x - X[n-1])/h;
    double result = table[n-1][0];
    double term = p;
    for(int i = 1;i<n;i++)
    {
       result += (term * table[n-1][i])/ fact(i);
       term *=(p+i);
    }
    return result;
}
int main()
{
    cout << "Enter  the number of data point :\n";
    int n;cin >> n ;
    vector<double>X(n);
    vector<double>Y(n);
    vector<vector<double>>table(n,vector<double>(n,0));
    cout << "Enter the X Values :\n";
    for(int i=0;i<n;i++)
    {
        cin >> X[i];
    }
    cout << "Enter the Y Values :\n";
    for(int i=0;i<n;i++)
    {
        cin >> Y[i];
        table[i][0] = Y[i];
    }
    backWardDiff(table , n );
    print(table , n ,X);
    int x;
    cout<<"Enter Interpollated Value:\n";
    cin>>x;
    double result = newtonBackwardDiffInter(table ,X,n,x);
    cout << result<<endl;
    return 0;
}
