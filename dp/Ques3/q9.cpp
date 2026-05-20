#include<iostream>
using namespace std;

// Minimum Number of Deletions and Insertions
// If the problem were to only include Deletion or only insertion then also the code would've been the same
// as these two operations are equivalent in counting the steps we need to do to make the two strings same
// https://www.naukri.com/code360/problems/minimum-number-of-deletions-and-insertions_4244510?leftPanelTabValue=PROBLEM
// https://leetcode.com/problems/delete-operation-for-two-strings/description/



// these codes are for naukri.com platform
// Recursion 
int solve(int index1, int index2, string &s1, string &s2){
    if(index1 < 0 || index2 < 0){
        if(index1 < 0 && index2 >= 0){
            return index2+1;
        }
        else if(index2 < 0 && index1 >= 0){
            return index1+1;
        }
        return 0;
    }

    if(s1[index1] == s2[index2]){
        return solve(index1-1, index2-1, s1, s2);
    }

    return 1 + min(solve(index1-1, index2, s1, s2), solve(index1, index2-1, s1, s2));
}
int canYouMake(string &s1, string &s2){
    int n = s1.length(), m = s2.length();
    return solve(n-1, m-1, s1, s2);
}



// Memoization 
int solve(int index1, int index2, string &s1, string &s2, vector<vector<int>> &dp){
    if(index1 < 0 || index2 < 0){
        if(index1 < 0 && index2 >= 0){
            return index2+1;
        }
        else if(index2 < 0 && index1 >= 0){
            return index1+1;
        }
        return 0;
    }
    if(dp[index1][index2] != -1){
        return dp[index1][index2];
    }

    if(s1[index1] == s2[index2]){
        return dp[index1][index2] = solve(index1-1, index2-1, s1, s2, dp);
    }

    return dp[index1][index2] = 1 + min(solve(index1-1, index2, s1, s2, dp), solve(index1, index2-1, s1, s2, dp));
}
int canYouMake(string &s1, string &s2){
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n-1, m-1, s1, s2, dp);
}

// Tabulation 
int canYouMake(string &s1, string &s2){
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // prepare the base cases
    for(int i = 1; i<=n; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i<=m; i++){
        dp[0][i] = i;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}




