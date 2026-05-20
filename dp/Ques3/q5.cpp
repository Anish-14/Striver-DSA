#include<iostream>
using namespace std;

// print LCS
// https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=PROBLEM


// Recursion + memo
// we just used the same method as in previous question, just in place of counting we are now saving the 
// character and forming a string by joining them all

string solve(int idx1, int idx2, string text1, string text2, vector<vector<string>> &dp){
    // base case
    if(idx1 < 0 || idx2 < 0){
        return "";
    }
    if(dp[idx1][idx2] != ""){
        return dp[idx1][idx2];
    }

    if(text1[idx1] == text2[idx2]){
        return dp[idx1][idx2] = text1[idx1] + solve(idx1-1, idx2-1, text1, text2, dp);
    }
    string s1 = solve(idx1-1, idx2, text1, text2, dp);
    string s2 = solve(idx1, idx2-1, text1, text2, dp);
    return dp[idx1][idx2] = s1.length() >= s2.length() ? s1 : s2;
}
string findLCS(int n, int m,string &s1, string &s2){
    vector<vector<string>> dp(n+1, vector<string>(m+1, ""));
    string ans = solve(n-1, m-1, s1, s2, dp);
    reverse(ans.begin(), ans.end());            // we reverse as we've saved the characters in reversed manner
    return ans;
}


// Tabulation 
string findLCS(int n, int m,string &text1, string &text2){
	vector<vector<string>> dp(n+1, vector<string> (m+1, ""));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = text1[i-1] + dp[i-1][j-1]; 
            }
            else{
                string s1 = dp[i-1][j];
                string s2 = dp[i][j-1];
                dp[i][j] = s1.length() >= s2.length() ? s1 : s2;
            }
        }
    }
    string ans = dp[n][m];
    reverse(ans.begin(), ans.end());

    return ans;
}

