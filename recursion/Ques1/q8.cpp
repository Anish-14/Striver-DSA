#include<iostream>
using namespace std;

// N Queens
// https://leetcode.com/problems/n-queens/

class Solution {
public:
    bool isSafe(vector<string> temp, int x, int y, int n){
        // column check
        for(int i = 0; i<x; i++){
            if(temp[i][y] == 'Q'){
                return false;
            }
        }

        // left Up Dia
        int i = x-1;
        int j = y-1;

        while(i >= 0 && j >= 0){
            if(temp[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }

        // right Up Dia
        i = x-1;
        j = y+1;

        while(i >= 0 && j < n){
            if(temp[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }

        return true;
    }
    void solve(int row, vector<vector<string>> &ans, vector<string> temp, int n){
        // base case
        if(row == n){
            ans.push_back(temp);
        }

        // we will by one row at a time
        string s(n, '.');
        for(int i = 0; i<n; i++){       // traverse all columns in the row
            if(isSafe(temp, row, i, n)){
                s[i] = 'Q';
                temp.push_back(s);
                solve(row+1, ans, temp, n);
                s[i] = '.';
                temp.pop_back();
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(0, ans, temp, n);

        return ans;
    }
};

