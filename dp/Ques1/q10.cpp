#include<iostream>
using namespace std;

// Minimum Falling path sum
// https://leetcode.com/problems/minimum-falling-path-sum/

// Recursion + Memoization
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        // base cases
        if(i >= matrix.size() || j < 0 || j >= matrix.size()){
            return 1e9;
        }
        if(i == matrix.size() - 1){
            return matrix[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int leftD = solve(i+1, j-1, matrix, dp);
        int down = solve(i+1, j, matrix, dp);
        int rightD = solve(i+1, j+1, matrix, dp);

        return dp[i][j] = matrix[i][j] + min(leftD, min(down, rightD));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix.size(), -1));
        int ans = INT_MAX;
        for(int i = 0; i<matrix.size(); i++){
            ans = min(ans, solve(0, i, matrix, dp));
        }

        return ans;
    }
};


// Tabulation 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n+2, 1e9));      // gave padding at each side of columns
        // base cases
        for(int j = 1; j<=n; j++){
            dp[n-1][j] = matrix[n-1][j-1];      // remember the matrix is not padded
        }

        for(int i = n-2; i>=0; i--){
            for(int j = 1; j<=n; j++){
                dp[i][j] = matrix[i][j-1] + min(dp[i+1][j-1], min(dp[i+1][j], dp[i+1][j+1]));
            }
        }

        int ans = INT_MAX;
        for(int i = 1; i<=n; i++){
            ans = min(ans, dp[0][i]);
        }

        return ans;
    }
};


