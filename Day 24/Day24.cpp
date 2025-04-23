#include<bits/stdc++.h>
using namespace std;
//Day 24 -Solution 

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    vector<vector<int>> merged;
    
    if(arr.empty()) return merged;
    
    sort(arr.begin(),arr.end());
    
    merged.push_back(arr[0]);
    int n=arr.size();
    
    for(int i=1;i<n;i++){
        vector<int>& last=merged.back();
        
        if(arr[i][0]<=last[1]){
            //overlapping case
            last[1]=max(arr[i][1],last[1]);
        }
        else{
            //no overlap
            merged.push_back(arr[i]);
        }
    }
    
    return merged;
}