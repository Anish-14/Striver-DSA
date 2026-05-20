#include<iostream>
using namespace std;

// buy and sell stock 2
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/


// Recurion + memo
class Solution {
public:
    int solve(int index, vector<int> &prices, bool buy, vector<vector<int>> &dp){
        // base case
        if(index >= prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        if(buy){
            return dp[index][buy] = max(-prices[index] + solve(index+1, prices, 0, dp), solve(index+1, prices, 1, dp));
        }

        return dp[index][buy] = max(prices[index] + solve(index+1, prices, 1, dp), solve(index+1, prices, 0, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, prices, 1, dp);
    }
};


// Tabulation 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int index = n-1; index>=0; index--){
            for(int buy = 0; buy<=1; buy++){
                if(buy){
                    dp[index][buy] = max(-prices[index] + dp[index+1][0], dp[index+1][1]);
                }
                else{
                    dp[index][buy] = max(prices[index] + dp[index+1][1], dp[index+1][0]);
                }
            }
        }

        return dp[0][1];
    }
};

// best solution (not intuitive though)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // just buy everytime you get the chance to
        for(int i = 1; i<prices.size(); i++){
            if(prices[i] - prices[i-1] > 0){
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};

