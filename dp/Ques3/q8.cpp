#include<iostream>
using namespace std;

// Minimum Insertion Steps to Make a String Palindrome
// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/


// Recursion + Memo
class Solution {
public:
    int solve(int start, int end, string &s, vector<vector<int>> &dp){
        if(start >= end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }

        if(s[start] == s[end]){
            return dp[start][end] = solve(start+1, end-1, s, dp);
        }

        return dp[start][end] = 1 + min(solve(start+1, end, s, dp), solve(start, end-1, s, dp));
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, s, dp);
    }       
};


// Tabulation 
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-1; i>=0; i--){
            for(int j = 0; j<n; j++){
                if(i >= j)  continue;
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }       
};

