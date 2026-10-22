#include<iostream>
using namespace std;

// buy and sell stock with transaction fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

// recursion + memo
// this is also the same as for the infinite transactions one, here we only subtracted the transaction fee after
// selling the stock

class Solution {
public:
    int f(int index, int buy, vector<int>&prices, int fee, vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        if(buy){
            return dp[index][buy] = max(-prices[index] + f(index+1,0,prices,fee,dp), 0 + f(index+1,1,prices,fee,dp));
        }
        else{
            return dp[index][buy] = max(prices[index] - fee + f(index+1,1,prices,fee,dp), f(index+1,0,prices,fee,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int ans = f(0, 1, prices, fee, dp);

        return ans > 0 ? ans : 0;
    }
};


// Tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // dp[n][0] and dp[n][1] are initialized to 0 (base case)
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Fill backwards from day n-1 down to day 0
        for(int index = n - 1; index >= 0; index--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 1){
                    dp[index][buy] = max(-prices[index] + dp[index + 1][0], 0 + dp[index + 1][1]);
                } 
                else{
                    dp[index][buy] = max(prices[index] - fee + dp[index + 1][1], 0 + dp[index + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};