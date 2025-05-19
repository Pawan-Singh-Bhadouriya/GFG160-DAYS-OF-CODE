#include<bits/stdc++.h>
using namespace std;
// Day 08 -Solution

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    
    for (int price : prices) {
        minPrice = min(minPrice, price); // Track the lowest price so far
        maxProfit = max(maxProfit, price - minPrice); // Check if current profit is max
    }
    
    return maxProfit;
}



