using namespace std;
#include<bits/stdc++.h>
// Day 54 - Solution

int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n=arr.size();
        int left=0,right=n-1;
        int count=0;
        
        while(left<right){
            int sum=arr[left]+arr[right];
            
            if(sum==target){
                if(arr[left]==arr[right]){
                    int len=right-left+1;
                    count+=(len*(len-1))/2;
                    break;
                }
                else{
                    int lCount=1,rCount=1;
                    while(left+1< right && arr[left]==arr[left+1]){
                        lCount++;
                        left++;
                    }
                    while(right-1> left && arr[right]==arr[right-1]){
                        rCount++;
                        right--;
                    }
                    
                    count+=(lCount*rCount);
                    left++;
                }
            }
            else if(sum<target) left++;
            else right--;
        }
        
        return count;
    }