#include <bits/stdc++.h>
using namespace std;
// Day 46-Solution

int findUnion(vector<int>& a, vector<int>& b) {        
        unordered_set<int> unionSet;
        
        for(int num:a){
            unionSet.insert(num);
        }
        
        for(int num:b){
            unionSet.insert(num);
        }
        
        return unionSet.size();
    }