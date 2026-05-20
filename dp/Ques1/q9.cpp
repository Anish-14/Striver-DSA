#include<iostream>
using namespace std;

//  Triangle
// https://leetcode.com/problems/triangle/


// Recur + Memo
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp, int n){
        if(j > i){
            return 1e9;
        }
        if(i == n-1){
            return triangle[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int bottom = solve(i+1, j, triangle, dp, n);
        int right = solve(i+1, j+1, triangle, dp, n);

        return dp[i][j] = triangle[i][j] + min(bottom, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, 0, triangle, dp, n);
    }
};


// Tabulation 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // base case is already included in it as our base case is the last row of this array only
        vector<vector<int>> dp = triangle;

        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<=i; j++){
                dp[i][j] += min(dp[i+1][j], dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};


