using namespace std;
#include<bits/stdc++.h>
// Day 01 - Solution

int getSecondLargest(vector<int> &arr) {
    if (arr.size() < 2) return -1; // Not enough elements

    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int num : arr) {
        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest && num != largest) {
            secondLargest = num;
        }
    }

    return (secondLargest == INT_MIN) ? -1 : secondLargest;
}


