#include<bits/stdc++.h>
using namespace std;
//Day 20- Solution

vector<int> computeLps(string& pat){
    int n=pat.length();
    vector<int> lps(n,0);
    int len=0;
    int i=1;
    
    while(i<n){
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0) len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

bool KMPSearch(string &pat,string &txt){
    int m=pat.length();
    int n=txt.length();
    vector<int> lps = computeLps(pat);
    
    int i=0,j=0;
    while(i<n){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==m) return true;
        
        else if(j<n && pat[j]!=txt[i]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    return false;
}

bool areRotations(string &s1, string &s2) {
    if(s1.length()!=s2.length()) return false;
    
    string temp = s1+s1;
    
    return KMPSearch(s2,temp);
}