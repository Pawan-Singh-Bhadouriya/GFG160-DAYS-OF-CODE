#include<bits/stdc++.h>
using namespace std;
//Day 34-Solution

bool isPossible(vector<int>& arr,int k,int maxPages){
    int student=1,pages=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>maxPages) return false;
        if(pages+arr[i]>maxPages){
            student++;
            pages=arr[i];
        }
        else{
            pages+=arr[i];
        }
    }
        return student<=k;
}

int findPages(vector<int> &arr, int k) {
    int n=arr.size();
    if(k>n) return -1; //not enough books
    
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int result =-1;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        
        if(isPossible(arr,k,mid)){
            result=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return result;
}