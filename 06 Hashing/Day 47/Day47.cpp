#include <bits/stdc++.h>
using namespace std;
// Day 47-Solution

int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> s(arr.begin(),arr.end());
        int longest=0;
        
        for(int num:arr){
            if(s.find(num-1)==s.end()){
                int currNum=num;
                int count=1;
                
                while(s.find(currNum+1)!=s.end()){
                    currNum++;
                    count++;
                }
                
                longest=max(longest,count);
            }
        }
        
        return longest;
    }