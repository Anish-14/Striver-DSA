#include<iostream>
using namespace std;

// Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/description/


// Recursion 
class Solution {
public:
    int solve(int idx1, int idx2, string text1, string text2){
        // base case
        if(idx1 < 0 || idx2 < 0){
            return 0;
        }

        if(text1[idx1] == text2[idx2]){
            cout<<"matched for "<< idx1<< " "<< idx2<<endl;
            return 1 + solve(idx1-1, idx2-1, text1, text2);
        }
        return max(solve(idx1-1, idx2, text1, text2), solve(idx1, idx2-1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        return solve(n-1, m-1, text1, text2);
    }
};


// Memo (this is giving TLE btw)
class Solution {
public:
    int solve(int idx1, int idx2, string text1, string text2, vector<vector<int>> &dp){
        // base case
        if(idx1 < 0 || idx2 < 0){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }

        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + solve(idx1-1, idx2-1, text1, text2, dp);
        }
        return dp[idx1][idx2] = max(solve(idx1-1, idx2, text1, text2, dp), solve(idx1, idx2-1, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n-1, m-1, text1, text2, dp);
    }
};

// Tabulation 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};


