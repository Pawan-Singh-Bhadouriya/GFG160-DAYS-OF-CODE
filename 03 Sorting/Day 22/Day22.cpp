#include<bits/stdc++.h>
using namespace std;
//Day 22 -Solution

int hIndex(vector<int>& citations) {
    int n=citations.size();
    vector<int> count(n+1,0);
    
    for(int c:citations){
        count[min(c,n)]++;
    }
    
    int total=0;    
    
    for(int i=n;i>=0;--i){
        total+=count[i];
        if(total>=i) return i;
    }
    
    return 0;
}