#include<iostream>
using namespace std;

// coin change
// https://leetcode.com/problems/coin-change/


// recursion + memo
class Solution {
public:
    int solve(int index, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(amount == 0) return 0;
        if(index < 0)  return 1e9;
        
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        int skip = solve(index - 1, coins, amount, dp);
        int take = 1e9;
        if(coins[index] <= amount){
            take = 1 + solve(index, coins, amount-coins[index], dp);
        } 

        return dp[index][amount] = min(skip, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(n-1, coins, amount, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};


// tabulation 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        // fill base cases first

        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0)   dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }

        for(int i = 1; i<n; i++){
            for(int val = 1; val <= amount; val++){
                int skip = dp[i-1][val];
                int take = 1e9;
                if(coins[i] <= val){
                    take = 1 + dp[i][val-coins[i]];
                } 

                dp[i][val] = min(skip, take);
            }
        }

        int ans = dp[n-1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};


// Optimised solution 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INF = 1e9;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int c : coins) {
            for (int amt = c; amt <= amount; amt++) {
                dp[amt] = min(dp[amt], 1 + dp[amt - c]);
            }
        }

        return dp[amount] >= INF ? -1 : dp[amount];
    }
};
