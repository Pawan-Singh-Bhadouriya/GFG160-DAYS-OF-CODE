#include<bits/stdc++.h>
using namespace std;
//Day 37-Solution

void rotateby90(vector<vector<int>>& mat) {
    // code here
    int n = mat.size();
    int m=n>0?mat[0].size():0;
    
    //finding the transpose of a matrix
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<m;j++){
            if(i<j){
            swap(mat[i][j],mat[j][i]);
            }
        }
    }
    
    //reversing the matrix
    
    for(int i=0;i<n;i++){
        int top=0,bottom=n-1;
        while(top<bottom){
            swap(mat[top][i],mat[bottom][i]);
            top++;
            bottom--;
        }
    }
}