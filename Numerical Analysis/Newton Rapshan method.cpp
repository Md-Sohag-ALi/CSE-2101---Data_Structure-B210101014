#include<bits/stdc++.h>
using namespace std;

double fx(double x)
{
   return pow(x,3) - 2*x - 5;
}
double fx_prime(double x)
{
   return 3*pow(x,2) - 2;
}
double NewtonRaphson(double x0 , double error)
{
    while(1)
    {
        double x1 = x0 - (fx(x0)/fx_prime(x0));
        if(x1 == x0)
        {
               return x1; //or return x0;
        }
        x0 = x1;
    }
}
int main()
{
    double x0,error;
 cout<< "Enter  the value  closer to zero that satisfied the given function:\n";
 cin >> x0;
 double root = NewtonRaphson(x0,error);
 cout <<fixed<<setprecision(3)<< root <<endl;
 return 0;
}
