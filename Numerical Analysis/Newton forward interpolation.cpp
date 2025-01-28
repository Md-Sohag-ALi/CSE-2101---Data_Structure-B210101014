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
double factorial(int num) {
    double fact = 1;
    for (int i = 2; i <= num; i++) {
        fact *= i;
    }
    return fact;
}
double newtonForwardInterpolation(vector<vector<double>>&table ,vector<double>&X , double x , int n)
{
    double h = X[1] -X[0];
    double p = (x - X[0])/h;
    double result = table[0][0];
    double term  = p;
     for (int i = 1; i < n; i++) {
        result += (term * table[0][i]) / (double) factorial(i);
        term *= (p - i);
    }

    return result;
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
double x;
cout << "Enter the value of x for interpolation:\n";
cin >> x;
double result = newtonForwardInterpolation(table , X , x,n);
cout <<"The Interpollated value: ";
cout <<result<<endl;
    return 0;
}

