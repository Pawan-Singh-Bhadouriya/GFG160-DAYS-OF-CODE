#include <bits/stdc++.h>
using namespace std;
// Day 49-Solution

int countSubarrays(vector<int> &arr, int k) {
        // code here
        unordered_map<int,int> prefixSumFreq;
        int count=0;
        int currentSum=0;
        
        prefixSumFreq[0]=1;
        
        for(int num:arr){
            currentSum+=num;
            
            if(prefixSumFreq.find(currentSum-k)!= prefixSumFreq.end()){
                count+=prefixSumFreq[currentSum-k];
            }
            prefixSumFreq[currentSum]++;
        }
        return count;
    }