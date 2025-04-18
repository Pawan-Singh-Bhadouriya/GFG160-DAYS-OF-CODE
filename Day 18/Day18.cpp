using namespace std;
#include<bits/stdc++.h>
// Day 18 - Solution

//LPS = Longest Prefix Suffix
 vector<int> computeLPSArray(const string& pat){
    int m=pat.length();
    vector<int> lps(m,0);
    int len=0;
    int i=1;
    
    while(i<m){
        
        if(pat[i]==pat[len]){
            len++;
            lps[i]=len;
            i++;
        }
        
        else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}    

vector<int> search(string& pat, string& txt) {
    // code here
    vector<int> result;
    int n=txt.length();
    int m=pat.length();
    
    // get the lps array for the patter
    vector<int> lps = computeLPSArray(pat);
    
    int i=0,j=0;
    
    while(i<n){
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        
        if(j==m){
            result.push_back(i-j);
            j=lps[j-1];
        }
        else if(i<n && pat[j]!= txt[i]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    return result;
}