#include <bits/stdc++.h>
using namespace std;
// Day 77 -Solution

class Solution {
  public:
    vector<vector<int>> res;
    
    bool isSafe(int row,int col, vector<int> &board){
        for(int i=0;i<col;++i){
            int prevRow = board[i];
            if(prevRow==row || abs(prevRow-row) == abs(i-col) ) return false;
        }
        return true;    
    }
    
    
    void solve(int col,int n,vector<int>& board){
        if(col==n){
            vector<int> sol(n);
            for(int i=0;i<n;++i){
                sol[i]=board[i]+1;
            }
            res.push_back(sol);
            return;
        }
        
        for(int row=0;row<n;++row){
            if(isSafe(row,col,board)){
                board[col]=row;
                solve(col+1,n,board);
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<int> board(n,-1);
        solve(0,n,board);
        return res;
    }
};