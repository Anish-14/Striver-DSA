#include<iostream>
using namespace std;

// Subset sum equals target (it should subsequence tbh)

// Recursion 
bool solve(int index, int n, int target, vector<int>&arr){
    if(index < 0 && target != 0){
        return 0;
    }
    if(target == 0){
        return 1;
    }

    return solve(index-1, n, target-arr[index], arr) || solve(index-1, n, target, arr);
}
bool subsetSumToK(int n, int k, vector<int> &arr) { 
    return solve(n-1, n, k, arr);
}


// Memoization     (this recursive method is better than the one above)
bool solve(int index, int target, vector<int>&arr, vector<vector<int>> &dp){
    if(target == 0) return 1;
    
    if(index == 0) return (arr[0] == target);
    
    if(dp[index][target] != -1){    
        return dp[index][target];
    }

    bool notTake = solve(index-1, target, arr, dp);
    bool take = false;
    if(arr[index] <= target){
        take = solve(index-1, target-arr[index], arr, dp);
    }

    return dp[index][target] = notTake || take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) { 
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve(n-1, k, arr, dp);
}


// Tabulation 
bool subsetSumToK(int n, int k, vector<int> &arr) { 
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    // base case
    for(int i = 0; i<n; i++){
        dp[i][0] = 1;
    }
    if(arr[0] <= k)
        dp[0][arr[0]] = 1;

    // bottom up
    for(int i = 1; i<n; i++){
        for(int target = 1; target <= k; target++){
            bool notTake = dp[i-1][target];
            bool take = 0;
            if(arr[i] <= target){
                take = dp[i-1][target-arr[i]];
            }
            dp[i][target] = notTake || take;
        }
    }

    return dp[n-1][k];
}
