#include<bits/stdc++.h>
using namespace std;
//Day 27 -Solution 

void mergeArrays(vector<int>& a, vector<int>& b) {
    // code here
 int n=a.size(),m=b.size();
 int gap = (n+m+1)/2;
 
 while(gap>0){
    int i=0,j=gap;
     
    while(j<(n+m)){
        int val_i = (i<n)? a[i]:b[i-n];
        int val_j = (j<n)? a[j]:b[j-n];
         
        if(val_i>val_j){
            if(i<n && j<n) swap(a[i],a[j]);
            else if(i<n && j>=n) swap(a[i],b[j-n]);
            else swap(b[i-n],b[j-n]);
        }
         
            i++;
            j++;
        }
        
        if(gap==1) gap=0;
        else gap = (gap/2) + (gap%2);
        
    }
}