using namespace std;
#include<bits/stdc++.h>
// Day 53 - Solution

vector<int> sumClosest(vector<int>& arr, int target) {
       int n = arr.size();
       if(n<2) return {};
       sort(arr.begin(),arr.end());
       
       int left = 0, right = n-1;
       int minDiff=INT_MAX,maxAbsDiff=INT_MIN;
       vector<int> result;
       
       while(left<right){
           int sum = arr[left]+arr[right];
           int diff = abs(sum-target);
               if(diff<minDiff || (diff==minDiff && abs(arr[right]-arr[left])>maxAbsDiff )){
                   result={arr[left],arr[right]};
                   minDiff=diff;
                   maxAbsDiff = abs(arr[right]-arr[left]);
               }
               
               if(sum<target) left++;
               else right--;
           }
        return result;
    }