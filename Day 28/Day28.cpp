#include<bits/stdc++.h>
using namespace std;
//Day 28 -Solution

int firstOccurance(vector<int>& arr,int target){
    int low=0,high=arr.size()-1,first=-1;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(arr[mid] == target){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    
    return first;
}

int lastOccurance(vector<int>& arr,int target){
    int low=0,high=arr.size()-1,last=-1;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(arr[mid] == target){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    
    return last;
}

int countFreq(vector<int>& arr, int target) {
    // code here
    int first = firstOccurance(arr,target);
    int last = lastOccurance(arr,target);
    
    if(first==-1) return 0;
    
    return (last-first+1);
}