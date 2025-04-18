using namespace std;
#include<bits/stdc++.h>
// Day 17 - Solution

char nonRepeatingChar(string &s) {
    // Your code here
    int freq[26] = {0};
    
    for(char c :s){
        freq[c-'a']++;
    }
    
    
    for(char c :s){
        if(freq[c-'a'] == 1) return c;
    }
    
    return '$';
}