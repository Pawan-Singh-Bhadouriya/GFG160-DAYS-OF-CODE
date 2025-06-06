#include<bits/stdc++.h>
using namespace std;
//Day 06 -Solution

vector<int> findMajority(vector<int>& arr) {
    int n=arr.size();
    int cnt1=0,cnt2=0,ele1=INT_MIN,ele2=INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i]!=ele2){
            cnt1=1;
            ele1=arr[i];
        }
        else if(cnt2==0 && arr[i]!=ele1){
            cnt2=1;
            ele2=arr[i];
        }
        else if(arr[i]==ele1) cnt1++;
        else if(arr[i]==ele2) cnt2++;
        
        else{
            cnt1--;
            cnt2--;
        }
    }
    
    vector<int> ans;
    cnt1=0,cnt2=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==ele1) cnt1++;
        if(arr[i]==ele2) cnt2++;
    }
    
    int mini=(int)((n/3) +1);
    
    if(cnt1>=mini) ans.push_back(ele1);
    if(cnt2>=mini) ans.push_back(ele2);
    
    sort(ans.begin(),ans.end());
    return ans;
}


