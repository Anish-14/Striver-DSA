#include<iostream>
using namespace std;

// Unique Paths with an obstacle
// https://leetcode.com/problems/unique-paths-ii/

// Recursion + Memoization 
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &nums, vector<vector<int>> &dp){
        // base case
        if(i >= nums.size() || j >= nums[0].size()){
            return 0;
        }
        if(nums[i][j] == 1){
            return 0;
        }
        if(i == nums.size() - 1 && j == nums[0].size() - 1){
            return 1;
        }

        if(dp[i][j] != -1)  return dp[i][j];

        int right = solve(i+1, j, nums, dp);
        int bottom = solve(i, j+1, nums, dp);

        return dp[i][j] = right + bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));

        return solve(0,0,obstacleGrid,dp);
    }
};



// Tabulation 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i = 0; i<m; i++){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            dp[i][0] = 1;
        }
        for(int j = 0; j<n; j++){
            if(obstacleGrid[0][j] == 1){
                break;
            }
            dp[0][j] = 1;
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};

