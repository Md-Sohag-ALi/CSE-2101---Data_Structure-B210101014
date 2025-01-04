#include<bits/stdc++.h>
using namespace std;
int Partition(vector<int>&arr, int st, int end)
{
    int pivot;
    pivot = arr[end];
    int i = st -1 ; //v.v.i
    for(int j = st; j < end ; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[end]);  //arr[end] means pivot
    return i; // i pivot index
}

void Q_Sort(vector<int>&arr, int st, int end)
{
    if(st < end)
    {
        int PiIdx = Partition(arr, st, end);
        Q_Sort(arr, st,PiIdx-1);
         for(int i =0 ; i < 5 ; i++)
    {
        cout <<arr[i]<<" ";
    }
    cout<<endl;
        Q_Sort(arr, PiIdx+1,end);
         for(int i =0 ; i < 5 ; i++)
    {
        cout <<arr[i]<<" ";
    }
    cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter size"<<endl;
    cin>>n;
     vector<int>arr(n);
    for(int i =0 ; i < n ; i++)
    {
        cin>>arr[i];
    }
    Q_Sort(arr, 0, n-1);

    //print
    for(int i =0 ; i < n ; i++)
    {
        cout <<arr[i]<<" ";
    }
    cout<<endl;
}
