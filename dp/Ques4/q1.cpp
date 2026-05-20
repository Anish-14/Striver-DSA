#include<iostream>
using namespace std;

// Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/description/

// Recursion + Memo
class Solution {
public:
    int solve(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
        // base cases
        if(ind1 < 0 && ind2 >= 0){
            return 0;
        }
        if(ind2 < 0){
            return 1;
        }
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = solve(ind1-1, ind2-1, s, t, dp) + solve(ind1-1, ind2, s, t, dp);
        }

        return dp[ind1][ind2] = solve(ind1-1, ind2, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s, t, dp);
    }
};


// Tabulation 
class Solution {
public:
    int mod = 1e9 + 7;      // there was some issue in storing the int values so I used mod although it wasn't told to use it
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // base cases
        for(int i = 0; i<=n; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] % mod + dp[i-1][j] % mod) % mod;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][m];
    }
};
