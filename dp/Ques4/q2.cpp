#include<iostream>
using namespace std;


// Edit distance
// https://leetcode.com/problems/edit-distance/description/

// recursion + Memoization 
class Solution {
public:
    int solve(int ind1, int ind2, string &word1, string &word2, vector<vector<int>> &dp){
        // base case
        if(ind2 < 0 && ind1 >= 0){
            return ind1 + 1;
        }
        if(ind1 < 0 && ind2 >= 0){
            return ind2+1;
        }
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }
        
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }

        if(word1[ind1] == word2[ind2]){
            // nothing --> just move to previous ones
            return dp[ind1][ind2] = solve(ind1-1, ind2-1, word1, word2, dp);
        }

        int del = solve(ind1-1, ind2, word1, word2, dp);
        int insert = solve(ind1, ind2-1, word1, word2, dp);
        int replace = solve(ind1-1, ind2-1, word1, word2, dp);

        return dp[ind1][ind2] = 1 + min(del, min(insert, replace));
    }
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};


// Tabulation 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // build base cases
        for(int i = 1; i<=n; i++){
            dp[i][0] = i;
        }
        for(int j = 1; j<=m; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int del = dp[i-1][j];
                    int insert = dp[i][j-1];
                    int replace = dp[i-1][j-1];
                    dp[i][j] = 1 + min(del, min(insert, replace));
                }
            }
        }

        return dp[n][m];
    }
};