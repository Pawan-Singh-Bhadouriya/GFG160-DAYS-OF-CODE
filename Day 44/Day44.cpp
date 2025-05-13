#include <bits/stdc++.h>
using namespace std;
// Day 44-Solution

vector<vector<int>> findTriplets(vector<int> &arr)
{
    unordered_map<int, vector<int>> mpp;
    int n = arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int val = -1 * (arr[i] + arr[j]);
            if (mpp.find(val) != mpp.end())
            {
                for (auto itr : mpp[val])
                {
                    ans.push_back({itr, i, j});
                }
            }
        }
        mpp[arr[i]].push_back(i);
    }
    return ans;
}