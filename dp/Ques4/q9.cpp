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



