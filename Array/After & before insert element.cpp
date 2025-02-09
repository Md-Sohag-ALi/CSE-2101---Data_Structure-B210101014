#include<bits/stdc++.h>
using namespace std;

void insert_after_given_num(int arr[],int &n,int x,int y) {
    int index= -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }

    if (index ==-1) {
        cout << "Element " << x << " not found in the array.\n";
        return;
    }

    for (int i = n; i > index + 1; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index +1] = y;
    n++;
}

void insert_before_given_num(int arr[],int &n,int x,int y) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Element " << x << " not found in the array.\n";
        return;
    }

    for (int i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = y;
    n++;
}

int main() {
    int arr[100], n;

    cout << "Enter number of elements in the array: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >>arr[i];
    }

    int x, y, choice;
    cout << "Enter 1 to insert after, 2 to insert before: ";
    cin >> choice;
    cout <<"Enter element to find: ";
    cin >> x;
    cout <<"Enter new element to insert: ";
    cin >> y;

    if (choice == 1) {
        insert_after_given_num(arr,n,x,y);
    } else if (choice == 2) {
        insert_before_given_num(arr,n, x, y);
    } else {
        cout << "Invalid choice.\n";
    }

    cout << "Updated array: ";
    for (int i = 0; i <n; i++) {
        cout <<arr[i] << " ";
    }
    cout <<"\n";

    return 0;
}
