#include <bits/stdc++.h>
using namespace std;
// Day 74 -Solution

class LRUCache {
  private:
    int capacity ;
    list<pair<int,int>> dll;
    unordered_map<int ,list<pair<int,int>> :: iterator>mp;
  public:
    LRUCache(int cap) {
        // code here
        capacity= cap;
    }

    int get(int key) {

        if(mp.find(key) == mp.end()){
            return -1;
        }
        
        dll.splice(dll.begin(),dll,mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->second=value;
            dll.splice(dll.begin(),dll,mp[key]);
            return;
        }
        
        if(dll.size() == capacity){
            int lrukey = dll.back().first;
            dll.pop_back();
            mp.erase(lrukey);
        }
        
        dll.push_front({key,value});
        mp[key] = dll.begin();
    }
};