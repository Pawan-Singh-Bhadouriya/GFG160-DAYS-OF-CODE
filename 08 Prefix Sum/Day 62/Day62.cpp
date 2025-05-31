using namespace std;
#include <bits/stdc++.h>
// Day 62 - Solution

int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int>prefixSumIndex;
        int currSum=0,longestLength=0;
        int n=arr.size();
        
        for(int i=0;i<n;++i){
            currSum+=arr[i];
            
            if(currSum==k) longestLength=i+1;
            
            if(prefixSumIndex.find(currSum-k)!=prefixSumIndex.end()){
                int length = i-prefixSumIndex[currSum-k];
                longestLength=max(longestLength,length);
            }
            
            if(prefixSumIndex.find(currSum)==prefixSumIndex.end()){
                prefixSumIndex[currSum]=i;
            }
        }
        return longestLength;
    }