using namespace std;
#include<bits/stdc++.h>
// Day 14 - Solution

int myAtoi(char *s) {
    int sign=1;
    long result=0;
    
    int i=0;
    
    //skipping the leading white spaces
    while(s[i]==' ') i++;
    
    //checking fo sign
    if(s[i]=='+' || s[i]=='-'){
        if(s[i]=='-') sign=-1;
        i++;
    }
    
    while(s[i]>='0' && s[i]<='9'){
        result =result *10+(s[i]-'0');
        
        //handle overflow
        if(result*sign>INT_MAX) return INT_MAX;
        if(result*sign<INT_MIN) return INT_MIN;
        
        i++;
    }
    
    return (int)(result * sign);
    
}
