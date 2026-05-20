#include<iostream>
using namespace std;

// Unique paths
// https://leetcode.com/problems/unique-paths/

// Memoization
// instead of going from right and down from start, we're going left and up from back
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp){    
        if(i == 0 && j == 0)    return 1;
        if(i < 0 || j < 0)      return 0;

        if(dp[i][j] != -1)  return dp[i][j];
        int up = solve(i-1,j,dp);
        int left = solve(i,j-1,dp);

        return dp[i][j] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return solve(m-1, n-1, dp);
    }
};

// Tabulation 
int uniquePaths(int m, int n) {
    if(m == 1 || n == 1)    return 1;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // mark the first row and column as 1
    for(int i = 0; i<m; i++){
        dp[i][0] = 1;
    }
    for(int i = 0; i<n; i++){
        dp[0][i] = 1;
    }

    for(int i = 1; i<m; i++){
        for(int j = 1; j<n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}


// Space Optimisation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,1);
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                prev[j] = prev[j-1] + prev[j];          // the prev[j] on RHS is the up cell and prev[j-1] is the left one
            }
        }

        return prev[n-1];
    }
};

// best solution, Maths based
class Solution {
public:
    int uniquePaths(int m, int n) {
        // nCr formulae apply karo
        // because if we want to go to our destination then we will take m+n-2 steps
        // that's for sure and if we fix one of our right or down steps then we can 
        // reach that destination
        // m-1 --> down steps and n-1 --> right steps
        // so we can choose any of these two
        int N = m+n-2;
        int r = m-1;
        double res = 1;

        for(int i = 1; i<=r; i++){
            res = res * (N-r+i)/i;
        }
        
        return (int)res;
    }
};


