#include<iostream>
using namespace std;

// Minimum path sum
// https://leetcode.com/problems/minimum-path-sum/



// Recursion + Memo
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i >= grid.size() || j >= grid[0].size()){
            return 1e9;
        }
        if(i == grid.size() - 1 && j == grid[0].size() - 1){
            return grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int right = solve(i, j+1, grid, dp);
        int bottom = solve(i+1, j, grid, dp);

        return dp[i][j] = grid[i][j] + min(right, bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(0, 0, grid, dp);
    }
};


// Tabulation  (We can space optimise it two a dp with size n too)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp = grid;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 1; i<m; i++){
            dp[i][0] += dp[i-1][0];
        }
        for(int i = 1; i<n; i++){
            dp[0][i] += dp[0][i-1];
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m-1][n-1];
    }
};

