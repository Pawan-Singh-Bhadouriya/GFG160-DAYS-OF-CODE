#include<bits/stdc++.h>
using namespace std;
// Day 02 -Solution

void moveZerosToEnd(vector<int> &arr) {
    int n = arr.size();
    int nonZeroIndex = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[nonZeroIndex]);
            nonZeroIndex++;
        }
    }
}


