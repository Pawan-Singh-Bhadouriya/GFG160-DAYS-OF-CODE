using namespace std;
#include<bits/stdc++.h>
// Day 16 - Solution

// Function is to check whether two strings are anagram of each other or not.
bool areAnagrams(string& s1, string& s2) {
    if(s1.length()!= s2.length()) return false;
        
    int cnt[26] ={0};
        
    for(int i=0;i<s1.length();i++){
        cnt[s1[i]-'a']++;
        cnt[s2[i]-'a']--;
    }
        
    for(int i=0;i<26;i++){
        if(cnt[i]!=0) return false;
    }
        
    return true;
}