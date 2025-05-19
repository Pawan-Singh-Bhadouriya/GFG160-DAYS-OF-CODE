#include<bits/stdc++.h>
using namespace std;
// Day 12 -Solution

int kadane(vector<int>& arr) {
    int maxEndingHere = arr[0], maxSoFar = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}

int circularSubarraySum(vector<int>& arr) {
    int n = arr.size();
    
    // Case 1: Non-circular max sum
    int max_kadane = kadane(arr);
    
    // Case 2: Circular max sum
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
        arr[i] = -arr[i]; // Inverting the elements
    }
    
    int max_inverse_kadane = kadane(arr); // This is actually min subarray sum
    
    int circular_max = total_sum + max_inverse_kadane;
    
    // If all numbers are negative, circular_max will be 0
    if (circular_max == 0)
        return max_kadane;
    
    return max(max_kadane, circular_max);
}


