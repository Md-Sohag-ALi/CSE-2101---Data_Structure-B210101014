#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin >> n;
    int arr [1000];
    for(int i = 1; i <= n ;i ++)
    {
        cin >> arr[i];
    }
     arr[0] = INT_MIN;
    for(int i = 2; i <= n ;i ++)
    {
        int temp = arr[i];
        int ptr = i - 1;
        while(temp < arr[ptr]  )
        {
            arr[ptr + 1] = arr[ptr];
            ptr = ptr - 1;
        }
        arr[ptr +1 ] = temp;
    }


    for(int i = 1 ;i <= n; i ++)
    {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
    return 0;
}
