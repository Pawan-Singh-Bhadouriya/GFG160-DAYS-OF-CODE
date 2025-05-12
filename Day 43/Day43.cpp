#include <bits/stdc++.h>
using namespace std;
// Day 43-Solution

int countPairs(vector<int> &arr, int target)
{
    unordered_map<int, int> mpp;
    int count = 0;

    for (int num : arr)
    {
        int more = target - num;
        if (mpp.find(more) != mpp.end())
        {
            count += mpp[more];
        }
        mpp[num]++;
    }
    return count;
}