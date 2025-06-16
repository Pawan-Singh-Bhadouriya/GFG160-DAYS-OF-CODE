#include <bits/stdc++.h>
using namespace std;
// Day 78 -Solution

bool isSafe(int row, int col, int num, vector<vector<int>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == num || board[i][col] == num)
            return false;

        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;

        if (board[boxRow][boxCol] == num)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            if (board[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isSafe(row, col, num, board))
                    {
                        board[row][col] = num;
                        if (solve(board))
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &mat)
{
    solve(mat);
}