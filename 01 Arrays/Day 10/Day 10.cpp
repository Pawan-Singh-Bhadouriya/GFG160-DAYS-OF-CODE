#include<bits/stdc++.h>
using namespace std;
// Day Day 10 program

int maxSubarraySum(vector<int> &arr) {
    // Your code here
    int sum=0,maxSum=INT_MIN;
    
    for(auto it:arr){
        sum+=it;
        maxSum = max(maxSum,sum);
        if(sum<0) sum=0;
    }
    
    return maxSum;
}
