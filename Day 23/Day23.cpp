#include<bits/stdc++.h>
using namespace std;
//Day 23 -Solution 
 
 int mergesort(vector<int>& arr,vector<int>& temp,int left,int right){
        int inv_count=0;
        if(left<right){
            int mid=left+(right-left)/2;
            
            inv_count+=mergesort(arr,temp,left,mid);
            inv_count+=mergesort(arr,temp,mid+1,right);
            
            int i=left, j=mid+1,k=left;
        
            while(i<=mid && j<=right){
                if(arr[i]<=arr[j]){
                    temp[k++]=arr[i++];
                }
                else{
                    temp[k++]=arr[j++];
                    inv_count+=(mid-i+1);
                }
            }
            while(i<=mid) temp[k++]=arr[i++];
            while(j<=right) temp[k++]=arr[j++];
        
            //copying the sorted temp into the original arr
            for(int k=left;k<=right;k++){
                arr[k] = temp[k];
            }
        
        }
        return inv_count;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        vector<int> temp(n);
        return mergesort(arr,temp,0,n-1);
    }