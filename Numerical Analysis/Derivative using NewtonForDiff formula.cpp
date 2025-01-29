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
double derivative_usingNewForward(vector<vector<double>>&table ,vector<double>&X,int n, double x0)
{
    double h = X[1] -X[0];
    double derivative_1 ;
    int index;
    for(int i = 0;i<n;i++)
    {
        if(X[i] == x0)
        {
            index = i;
            break;
        }
    }
    derivative_1 = (( table[index][1]) - 1/2.0*(table[index][2]) + 1/3.0*(table[index][3]) - 1/4.0*(table[index][4]) + 1/5.0*(table[index][5])) /h;
    return derivative_1;
}
double second_derivative(vector<vector<double>>& table, vector<double>& X, int n, double x0) {
    double h = X[1] - X[0];
    int index;

    for (int i = 0; i < n; i++) {
        if (X[i] == x0) {
            index = i;
            break;
        }
    }
     double derivative_2 = ((table[index][2]) - (table[index][3]) + 11 / 12.0 * (table[index][4]) -
                            5 / 6.0 * (table[index][5])) / (h * h);

    return derivative_2;
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
double x0;
cout << "Enter the value of x for derivative :\n";
cin >> x0;
double result = derivative_usingNewForward(table , X ,n ,x0);
cout <<"The second-order derivative at x = ";
cout <<result<<endl;
  double second_result = second_derivative(table, X, n, x0);
    cout << "The second-order derivative at x = " << x0 << " is: " << second_result << endl;
    return 0;
}

