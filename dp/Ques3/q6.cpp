#include<iostream>
using namespace std;

// Longest common subset
// https://www.naukri.com/code360/problems/longest-common-substring_1214702?leftPanelTabValue=PROBLEM

// Striver --> DP 27

int memo[1001][1001][1001]; // Assuming max lengths around 1000

int solveMemo(int i, int j, int count, string &str1, string &str2, vector<vector<vector<int>>> &dp) {
    if (i == 0 || j == 0) {
        return count;
    }

    if (dp[i][j][count] != -1) {
        return dp[i][j][count];
    }

    int same = count;
    if (str1[i - 1] == str2[j - 1]) {
        same = solveMemo(i - 1, j - 1, count + 1, str1, str2, dp);
    }

    int diff1 = solveMemo(i - 1, j, 0, str1, str2, dp);
    int diff2 = solveMemo(i, j - 1, 0, str1, str2, dp);

    return dp[i][j][count] = max({same, diff1, diff2});
}

int LCSubStr(string &str1, string &str2) {
    int n = str1.length();
    int m = str2.length();
    
    // dp[n+1][m+1][max(n,m)+1] initialized to -1
    int maxLen = min(n, m);
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(maxLen + 1, -1)));

    return solveMemo(n, m, 0, str1, str2, dp);
}





// another one
int solve2D(int i, int j, string &str1, string &str2, vector<vector<int>> &dp, int &maxLen) {
    if (i == 0 || j == 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    // Always compute recursive subproblems to ensure full exploration
    solve2D(i - 1, j, str1, str2, dp, maxLen);
    solve2D(i, j - 1, str1, str2, dp, maxLen);

    if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = 1 + solve2D(i - 1, j - 1, str1, str2, dp, maxLen);
        maxLen = max(maxLen, dp[i][j]);
    } else {
        dp[i][j] = 0;
    }

    return dp[i][j];
}
int LCSubStr(string &str1, string &str2) {
    int n = str1.length(), m = str2.length();
    // dp[i][j] represents the length of the longest common suffix ending at str1[i-1] and str2[j-1].
    // Threfore we have to save the answer in maxAns and dp[i][j] is not storing our answer here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int maxLen = 0;
    solve2D(n, m, str1, str2, dp, maxLen);
    return maxLen;
}


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


