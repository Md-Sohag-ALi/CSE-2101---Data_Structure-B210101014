#include<bits/stdc++.h>
using namespace std;
void del(int arr[],int &n,int x)
{
    for(int i = x-1 ;i<n;i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}
int main()
{
    int arr[100];
    int n;cin>>n;
  for(int i=0;i<n;i++)
  {
      cin >>arr[i];
  }
    cout<<"Enter Position to delete\n";
    int x;
    cin>>x;
    del(arr ,n ,x);
for(int i=0;i<n;i++)
    cout<<arr[i] <<" ";
    return 0;
}
