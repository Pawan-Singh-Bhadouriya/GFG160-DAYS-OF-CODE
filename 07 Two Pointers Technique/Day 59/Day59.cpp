using namespace std;
#include <bits/stdc++.h>
// Day 59 - Solution

int maxWater(vector<int> &arr)
{
    int n = arr.size();
    if (n < 3)
        return 0;

    vector<int> left_max(n), right_max(n);
    int water = 0;

    left_max[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left_max[i] = max(left_max[i - 1], arr[i]);
    }

    right_max[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right_max[i] = max(right_max[i + 1], arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int trapped = min(left_max[i], right_max[i]) - arr[i];
        if (trapped > 0)
            water += trapped;
    }
    return water;
}