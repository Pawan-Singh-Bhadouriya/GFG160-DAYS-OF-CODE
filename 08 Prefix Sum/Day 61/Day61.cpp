using namespace std;
#include <bits/stdc++.h>
// Day 61 - Solution

int findEquilibrium(vector<int> &arr)
{
    int totalSum = 0;

    for (int num : arr)
    {
        totalSum += num;
    }

    int n = arr.size();
    int lSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum -= arr[i];
        if (lSum == totalSum)
            return i;

        lSum += arr[i];
    }
    return -1;
}