// Frog jump 
// https://www.naukri.com/code360/problems/frog-jump_3621012?leftPanelTabValue=PROBLEM

#include<iostream>
using namespace std;

// Recursion
int solve(int n, vector<int> &heights){
    if(n <= 0){
        return 0;
    }

    int left = abs(heights[n] - heights[n-1]) + solve(n-1, heights);
    int right = INT_MAX;
    if(n-2 >= 0){
        right = abs(heights[n] - heights[n-2]) + solve(n-2, heights);
    }

    return min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    return solve(n-1, heights);
}

// memo
int solve(int n, vector<int> &heights, vector<int> &dp){
    if(n <= 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int left = abs(heights[n] - heights[n-1]) + solve(n-1, heights, dp);
    int right = INT_MAX;
    if(n-2 >= 0){
        right = abs(heights[n] - heights[n-2]) + solve(n-2, heights, dp);
    }

    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return solve(n-1, heights, dp);
}

// Tabulation 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);

    for(int i = 1; i<n; i++){
        int left = abs(heights[i] - heights[i-1]) + dp[i-1];
        int right = INT_MAX;
        if(i >= 2){
            right = abs(heights[i] - heights[i-2]) + dp[i-2];
        }
        dp[i] = min(left, right);
    }

    return dp[n-1];
}

// space optimisation
int frogJump(int n, vector<int> &heights)
{
    int justLeft = 0;
    int leftToLeft = 0;

    for(int i = 1; i<n; i++){
        int left = abs(heights[i] - heights[i-1]) + justLeft;
        int twoLeft = INT_MAX;
        if(i >= 2){
            twoLeft = abs(heights[i] - heights[i-2]) + leftToLeft;
        }

        leftToLeft = justLeft;
        justLeft = min(left, twoLeft);
    }

    return justLeft;
}

