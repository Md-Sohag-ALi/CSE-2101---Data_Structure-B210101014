#include<bits/stdc++.h>
using namespace std;

void countSort(int inArr[], int n, int pos) {
    int outArr[n];
    int countArr[10] = {0};

    for (int i = 0; i < n; i++) {
        countArr[(inArr[i] / pos) % 10]++;
    }

    for (int i = 1; i <= 9; i++) {
        countArr[i] += countArr[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        outArr[--countArr[(inArr[i] / pos) % 10]] = inArr[i];
    }

    for (int i = 0; i < n; i++) {
        inArr[i] = outArr[i];
    }
}

void radixSort(int inArr[], int n) {
    int maxVal = *max_element(inArr, inArr + n);
    for (int pos = 1; maxVal / pos > 0; pos *= 10) {
        countSort(inArr, n, pos);
    }
}

int main() {
    int n;
    cin >> n;
    int inArr[n];
    for (int i = 0; i < n; i++) {
        cin >> inArr[i];
    }

    radixSort(inArr, n);

    for (int i = 0; i < n; i++) {
        cout << inArr[i] << " ";
    }
    cout << endl;

    return 0;
}
