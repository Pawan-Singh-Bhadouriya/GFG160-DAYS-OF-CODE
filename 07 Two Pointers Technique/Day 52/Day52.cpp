using namespace std;
#include<bits/stdc++.h>
// Day 52 - Solution

int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        int count=0;
        int n=arr.size();
        int left=0,right=n-1;
        
        while(left<right){
            if(arr[left]+arr[right]<target){
                count+=right-left;
                left++;
            }
            else{
                right--;
            }
        }
        return count;
    }