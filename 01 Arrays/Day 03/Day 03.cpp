#include<bits/stdc++.h>
using namespace std;
//Day 03 -Solution

void reverseArray(vector<int> &arr) {
    int n = arr.size();
    int i = 0, j = n - 1;
    
    while (i < j) {
        swap(arr[i], arr[j]); // Correctly swaps elements in the array
        i++;
        j--;
    }
}


