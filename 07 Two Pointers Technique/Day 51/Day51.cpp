using namespace std;
#include<bits/stdc++.h>
// Day 51 - Solution

int countTriplets(vector<int> &arr, int target) {
      int n = arr.size();
      int count=0;
      for(int i=0;i<n-2;i++){
          int left=i+1;
          int right=n-1;
          
          while(left<right){
              int sum=arr[i]+arr[left]+arr[right];
              
              if(sum==target){
                  if(arr[left]==arr[right]){
                      int len=right-left+1;
                      count+=(len*(len-1))/2;
                      break;
                  }else{
                    int lCount=1,rCount=1;
                    while(left+1<right && arr[left] == arr[left+1]){
                        lCount++;
                        left++;
                    }
                    while(right-1>left && arr[right] == arr[right-1]){
                        rCount++;
                        right--;
                    }
                    count+=(lCount*rCount);
                    left++;
                    right--;
                  }
              }
              
             else if(sum<target) left++;
             else right--;
          }
      }
      return count;
    }