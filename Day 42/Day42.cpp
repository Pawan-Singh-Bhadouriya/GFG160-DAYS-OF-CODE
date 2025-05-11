#include<bits/stdc++.h>
using namespace std;
//Day 42-Solution

bool twoSum(vector<int>& arr, int target) {
        // code here
        map<int,int> mpp;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            int a=arr[i];
            int more=target-a;
            
            if(mpp.find(more)!=mpp.end()){
                return true;
            }
            
            mpp[a]=i;
        }
        return false;
    }