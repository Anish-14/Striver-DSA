#include<iostream>
using namespace std;


// Wildcard Matching 
// https://leetcode.com/problems/wildcard-matching/
// this was a bit difficult as its base case was quite hard to get

// Recursion + memo
class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        // base cases
        if(i < 0 && j >= 0 || j < 0 && i >= 0){
            if(j >= 0 && p[j] == '*'){
                return solve(i, j-1, s, p, dp);
            }
            else{
                return false;
            }
        }
        if(i < 0 || j < 0){
            return true;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(i-1, j-1, s, p, dp);
        }
        if(p[j] == '*'){
            return dp[i][j] = solve(i-1, j-1, s, p, dp) || solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
        }
        
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, p, dp);
    }
};


// Tabulation 
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base cases
        dp[0][0] = 1;
        for(int j = 1; j<=m; j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-1];
            }
            else{
                dp[0][j] = 0;
            }
        }
        for(int i = 1; i<=n; i++){
            dp[i][0] = 0;
        }
        

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                }
                else 
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};