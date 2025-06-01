using namespace std;
#include <bits/stdc++.h>
// Day 63 - Solution

int maxLen(vector<int> &arr)
{
    unordered_map<int, int> prefixSumIndex;
    int maxlen = 0, sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum += (arr[i] == 0) ? -1 : 1;

        if (sum == 0)
        {
            maxlen = i + 1;
        }

        if (prefixSumIndex.find(sum) != prefixSumIndex.end())
        {
            maxlen = max(maxlen, i - prefixSumIndex[sum]);
        }
        else
        {
            prefixSumIndex[sum] = i;
        }
    }
    return maxlen;
}