using namespace std;
#include<bits/stdc++.h>
// Day 15 - Solution

string addBinary(string& s1, string& s2) {
    int i = s1.length()-1;
    int j = s2.length()-1;
    int carry=0;
    string result="";
    
    while(i>=0 || j>=0 || carry){
        int sum= carry;
        
        if(i>=0) sum+=s1[i--]-'0';
        if(j>=0) sum+=s2[j--]-'0';
        
        result= char(sum%2 +'0')+result;
        carry=sum/2;
    }
    
    int pos = result.find_first_not_of('0');
    if(pos!=string::npos){
        return result.substr(pos);
    }
    
    
    return "0";
}