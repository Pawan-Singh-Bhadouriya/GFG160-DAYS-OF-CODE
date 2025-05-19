#include <bits/stdc++.h>
using namespace std;
// Day 45-Solution

vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        unordered_set<int> resultSet;
        unordered_set<int> setA(a.begin(),a.end());
        
        for(int num:b){
            if(setA.find(num)!=setA.end()){
                resultSet.insert(num);
                setA.erase(num);
            }
        }
        
        vector<int> result(resultSet.begin(),resultSet.end());
        sort(result.begin(),result.end());
        
        return result;
        
    }