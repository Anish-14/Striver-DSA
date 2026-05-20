#include<iostream>
using namespace std;

// Cherry Pickup 2
// https://leetcode.com/problems/cherry-pickup-ii/


// Recursion + memo     (3D dp problem)
class Solution {
public:
    int solve(int i, int j1, int j2, vector<vector<int>>& grid, int n, int m, vector<vector<vector<int>>> &dp){
        // base cases
        if(i >= n || j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
            return 0;
        }
        if(i == n-1){
            if(j1 == j2)    return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1){
            return dp[i][j1][j2];
        }

        int maxi = INT_MIN;
        for(int r1 = -1; r1<=1; r1++){
            for(int r2 = -1; r2<=1; r2++){
                maxi = max(maxi, solve(i+1, j1+r1, j2+r2, grid, n, m, dp));
            }
        }

        if(j1 == j2)    return dp[i][j1][j2] = grid[i][j1] + maxi;
        return dp[i][j1][j2] = grid[i][j1] + grid[i][j2] + maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return solve(0, 0, m-1, grid, n, m, dp);    // i, j1, j2 as the row is same for both the robots 
    }
};

// Tabulation 
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m+2, vector<int>(m+2, 0)));

        // base case and remember we've given padding to dp only not the grid matrix
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=m; j++){
                if(i == j)  dp[n-1][i][j] = grid[n-1][i-1];
                else{
                    dp[n-1][i][j] = grid[n-1][i-1] + grid[n-1][j-1];
                }
            }
        }

        for(int i = n-2; i>=0; i--){
            for(int j1 = 1; j1<=m; j1++){
                for(int j2 = 1; j2<=m; j2++){

                    int maxi = INT_MIN;
                    for(int r1 = -1; r1<=1; r1++){
                        for(int r2 = -1; r2<=1; r2++){
                            maxi = max(maxi, dp[i+1][j1+r1][j2+r2]);
                        }
                    }

                    if(j1 == j2)    dp[i][j1][j2] = grid[i][j1-1] + maxi;
                    else{
                        dp[i][j1][j2] = grid[i][j1-1] + grid[i][j2-1] + maxi;
                    }
                }
            }
        }
        
        return dp[0][1][m];
    }
};
