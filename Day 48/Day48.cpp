#include <bits/stdc++.h>
using namespace std;
// Day 48-Solution

vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string,vector<string>> anagramMap;
        vector<string> order;
        
        for(string word : arr){
            string sortedWord = word;
            sort(sortedWord.begin(),sortedWord.end());
            
            if(anagramMap.find(sortedWord) == anagramMap.end()){
                order.push_back(sortedWord);
            }
            anagramMap[sortedWord].push_back(word);
        }
        
        vector<vector<string>> res;
        for(string key :order){
            res.push_back(anagramMap[key]);
        }
        
        return res;
    }
