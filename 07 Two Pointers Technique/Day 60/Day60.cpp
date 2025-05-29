using namespace std;
#include <bits/stdc++.h>
// Day 60 - Solution

int maxWater(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = n - 1;
    int maxWater = 0;

    while (left < right)
    {
        int currentHeight = min(arr[left], arr[right]);
        int width = right - left;
        int currentArea = currentHeight * width;
        maxWater = max(maxWater, currentArea);

        if (arr[left] < arr[right])
            left++;
        else
            right--;
    }
    return maxWater;
}