#include<bits/stdc++.h>
using namespace std;
double fx(double x)
{
    return x*x*x - 2*x  - 5;
}
double bisection(double a , double b,double tolarence)
{
    while(1)
    {
        double mid  = (a+b) /2.0;
        double f = fx(mid);
        if(f > 0)
        {
            b = mid;
        }
        if(f<0)
        {
            a = mid;
        }
        if(f == 0 || abs(f)<=tolarence)
        {
            return mid;
        }
    }

}
int main()
{
    double a,b,tolarence;
    cout<<"Enter Interval :\n";
    cin >> a >>b ;
    cout <<"Enter  tolarence/Error:\n";
    cin >> tolarence;
    double root = bisection(a , b , tolarence);
    cout <<fixed<<setprecision(4) << root <<endl;
    return 0;
}
