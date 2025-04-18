#include<bits/stdc++.h>
using namespace std;
// Day 11 -Solution

int maxProduct(vector<int> &arr) {
    int n = arr.size();
    
    int mini = arr[0];         // Tracks the current minimum product
    int maxi = arr[0];         // Tracks the current maximum product
    int result = arr[0];       // Stores the overall max product found so far

    for(int i=1;i<n;i++){
        if(arr[i] < 0) swap(maxi, mini); // If current number is negative, swap

        // Update max and min product ending at current index
        maxi = max(arr[i], arr[i]*maxi);
        mini = min(arr[i], arr[i]*mini);

        result = max(result, maxi); // Update result if needed
    }

    return result;
}
