// Day 13 program
#include<bits/stdc++.h>
using namespace std;
// Function to find the smallest positive number missing from the array.

int missingNumber(vector<int> &arr) {
    int n = arr.size();
    
    for(int i=0;i<n;i++){
        while(arr[i]>0 && arr[i]<=n && arr[arr[i]-1]!=arr[i]){
            swap(arr[i],arr[arr[i]-1]);
        }
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1) return i+1;
    }
    
    return n+1;
}