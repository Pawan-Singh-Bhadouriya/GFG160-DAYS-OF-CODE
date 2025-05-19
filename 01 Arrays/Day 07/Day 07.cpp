#include<bits/stdc++.h>
using namespace std;
//Day 07 -Solution

int maximumProfit(vector<int> &prices) {
    int profit = 0;
    int n = prices.size();
    
    for(int i = 1; i < n; i++) {
        if(prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1]; // Buy at i-1, sell at i
        }
    }
    
    return profit;
}


