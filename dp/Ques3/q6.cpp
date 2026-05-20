#include<iostream>
using namespace std;

// Longest common subset
// https://www.naukri.com/code360/problems/longest-common-substring_1214702?leftPanelTabValue=PROBLEM

// Striver --> DP 27

// Tabulation 
int LCSubStr(string &str1, string &str2){
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int ans = 0;

    // base case is that the first row and first column should be zero
    // which is already satisfied as we've initialised our dp with zeros only

    // imagine the words on each axis on the dp matrix
    // now if the ith and jth character matches then I'll ask
    // (i-1) & (j-1) that how much length can you make 
    // else I'll put there zero as it is not possible to make substring
    // from those indices as they're different
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}


