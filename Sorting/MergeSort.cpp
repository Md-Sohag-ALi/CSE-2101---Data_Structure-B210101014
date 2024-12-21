#include<bits/stdc++.h>
using namespace std;
void Merge (int arr[] , int left ,int  mid , int right)
{
    int nl ,nr;
    nl = mid -left + 1;
    nr = right - mid ;
    int L[nl] ,R[nr];
    for(int i =0;i<nl ;i++)
    {
        L[i] = arr[left + i] ;
    }
     for(int i =0;i<nr ; i++)
    {
        R[i] = arr[mid +1+ i] ;
    }
    int i=0 , j = 0 , k = left;
    while(i<nl && j< nr)
    {
        if(L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }
    while(i<nl)
    {
        arr[k++] = L[i++];
    }
     while(j<nr)
    {
        arr[k++] = R[j++];
    }

}
void mergeSort(int arr[] , int left ,int right)
{
    if(left >= right)
        return;
    int mid = left + (right -left)/2;
    mergeSort(arr , left , mid);
    mergeSort(arr , mid + 1 , right);
    Merge(arr , left ,mid,right);
}
int main()
{
    int ar_size;cin>>ar_size;
    int arr[ar_size];
    for(int i=0;i<ar_size;i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr , 0 , ar_size -1);
    for(int i= 0;i<ar_size ;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
