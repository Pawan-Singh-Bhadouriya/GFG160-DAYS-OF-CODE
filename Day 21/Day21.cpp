#include<bits/stdc++.h>
using namespace std;
//Day 21 -Solution

void sort012(vector<int>& arr) {
    int low = 0, mid = 0;
    int high = arr.size() - 1;
    
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
