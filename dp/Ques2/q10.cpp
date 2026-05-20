#include<iostream>
using namespace std;


// coin change 2
// https://leetcode.com/problems/coin-change-ii/description/

// recursion + memoisation 
class Solution {
public:
    int solve(int index, vector<int> &coins, int target, vector<vector<int>> &dp){
        if(index == 0){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }

        int notTake = solve(index-1, coins, target, dp);
        int take = 0;
        if(coins[index-1] <= target){
            take = solve(index, coins, target-coins[index-1], dp);
        }

        return dp[index][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(n, coins, amount, dp);   
    }
};


// Tabulation 
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<long long>> dp(n+1, vector<long long>(amount+1, 0));

        dp[0][0] = 1;

        for(int ind = 1; ind<=n; ind++){
            for(int target = 0; target <= amount; target++){
                long long notTake = dp[ind-1][target];
                long long take = 0;
                if(coins[ind-1] <= target){
                    take = dp[ind][target-coins[ind-1]];
                }

                dp[ind][target] = take + notTake;
            }
        }

        return (int)dp[n][amount];
    }
};



