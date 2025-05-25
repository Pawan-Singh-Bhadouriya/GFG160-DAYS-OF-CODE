using namespace std;
#include <bits/stdc++.h>
// Day 56 - Solution

vector<int> subarraySum(vector<int> &arr, int target)
{
    int start = 0, currentSum = 0;
    for (int end = 0; end < arr.size(); end++)
    {
        currentSum += arr[end];

        while (currentSum > target && start < end)
        {
            currentSum -= arr[start++];
        }

        if (currentSum == target)
        {
            return {start + 1, end + 1};
        }
    }
    return {-1};
}