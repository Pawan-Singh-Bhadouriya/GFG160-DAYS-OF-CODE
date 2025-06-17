#include <bits/stdc++.h>
using namespace std;
// Day 79 -Solution

bool dfs(vector<vector<char>> &mat, string &word, int x, int y, int idx)
{

    int n = mat.size();
    int m = mat[0].size();

    if (idx == word.size())
        return true;
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    if (mat[x][y] != word[idx])
        return false;

    char temp = mat[x][y];
    mat[x][y] = '#';

    bool found = dfs(mat, word, x + 1, y, idx + 1) ||
                 dfs(mat, word, x - 1, y, idx + 1) ||
                 dfs(mat, word, x, y + 1, idx + 1) ||
                 dfs(mat, word, x, y - 1, idx + 1);

    mat[x][y] = temp;

    return found;
}

bool isWordExist(vector<vector<char>> &mat, string &word)
{
    int n = mat.size(), m = mat[0].size();

    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (mat[x][y] == word[0])
            {
                if (dfs(mat, word, x, y, 0))
                    return true;
            }
        }
    }

    return false;
}