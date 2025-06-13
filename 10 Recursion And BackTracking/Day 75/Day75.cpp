#include <bits/stdc++.h>
using namespace std;
// Day 75 -Solution

void genPermutations(int n, string &curr, unordered_map<char, int> &cnt, vector<string> &res)
{
    if (curr.size() == n)
    {
        res.push_back(curr);
        return;
    }
    for (pair<char, int> it : cnt)
    {
        char c = it.first;
        int count = it.second;

        if (count == 0)
            continue;

        curr.push_back(c);
        cnt[c]--;

        // recurrsion to build the next char
        genPermutations(n, curr, cnt, res);

        // backtracking to remove the char and restore its cnt
        curr.pop_back();
        cnt[c]++;
    }
}
vector<string> findPermutation(string &s)
{
    vector<string> res;
    int n = s.size();
    unordered_map<char, int> cnt;

    for (char c : s)
    {
        cnt[c]++;
    }

    string curr = "";
    genPermutations(n, curr, cnt, res);
    return res;
}