#include <bits/stdc++.h>
using namespace std;
// Day 50-Solution

long subarrayXor(vector<int> &arr, int k) {
        
        unordered_map<int,int>freq;
        long count=0;
        int xorVal=0;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            xorVal^=arr[i];
            
            if(xorVal==k) count++;
            
            if(freq.find(xorVal^k) != freq.end()){
                count+=freq[xorVal^k];
            }
            
            freq[xorVal]++;
        }
        return count;
    }
