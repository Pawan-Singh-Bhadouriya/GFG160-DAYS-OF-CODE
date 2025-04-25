#include<bits/stdc++.h>
using namespace std;
//Day 26 -Solution 

bool static compare(vector<int>& a ,vector<int>& b ){
    return a[1]<b[1];
}

int minRemoval(vector<vector<int>> &intervals) {
    if(intervals.empty()) return 0;
    
    sort(intervals.begin(),intervals.end(),compare);
    
    int removeCount=0;
    int lastEnd = intervals[0][1];
    
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]< lastEnd){
            //removing all the overlapping intervals
            removeCount++;
        }
        else{
            lastEnd = intervals[i][1];
        }
    }
    return removeCount;
}