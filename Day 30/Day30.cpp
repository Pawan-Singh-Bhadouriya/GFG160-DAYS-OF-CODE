#include<bits/stdc++.h>
using namespace std;
//Day 30-Solution


int search(vector<int>& arr, int key) {
    // Code Here
    int n=arr.size();
    int low=0,high=n-1;
    
    while(low<=high){
        int mid= low+(high-low)/2;
        
        if(arr[mid]==key) return mid;
        
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
        }
        
        else if(arr[low]<=arr[mid]){
            if(key>=arr[low] && key<arr[mid]) high=mid-1;
            else low=mid+1;
        }
        else{
            if(key>arr[mid] && key<=arr[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}