#include<iostream>
using namespace std;

// buy and sell stock with cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// Recurison + Memo
// the only slight change in the code from unlimited transaction is that after selling we can not 
// buy on the right next index so we call buy "index+2" after selling. That's the only change here
class Solution {
public:
    int f(int index, int buy, vector<int>&prices, vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        if(buy){
            return dp[index][buy] = max(-prices[index] + f(index+1,0,prices,dp), 0 + f(index+1,1,prices,dp));
        }
        else{
            return dp[index][buy] = max(prices[index] + f(index+2,1,prices,dp), f(index+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0, 1, prices, dp);
    }
};


// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // DP table initialized to 0. 
        // Size n+2 eliminates out-of-bounds checks for (i+2) during cooldown.
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // Iterate backwards from the last day down to day 0
        for(int index = n - 1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                if (buy == 1) {
                    dp[index][buy] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
                } 
                else{
                    dp[index][buy] = max(prices[index] + dp[index + 2][1], 0 + dp[index + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};