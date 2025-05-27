using namespace std;
#include <bits/stdc++.h>
// Day 58 - Solution

int longestUniqueSubstr(string &s) {
       unordered_map<char,int> lastSeen;
       int maxLen=0;
       int start=0;
       
       for(int end=0;end<s.length();end++){
           char ch=s[end];
           
           if(lastSeen.find(ch)!=lastSeen.end() && lastSeen[ch]>= start){
               start=lastSeen[ch]+1;
           }
           
           lastSeen[ch]=end;
           maxLen=max(maxLen,end-start+1);
       }
       return maxLen;
    }