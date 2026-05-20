#include<iostream>
using namespace std;


// buy and sell stock 4
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/


// Recurison + Memoization 
class Solution {
public:
    int solve(int index, vector<int> &prices, int num, int k, vector<vector<int>> &dp){
        if(index >= prices.size() || num >= 2*k){
            return 0;
        }
        if(dp[index][num] != -1){
            return dp[index][num];
        }

        if(num % 2 == 0){ // buy
            return dp[index][num] = max(-prices[index] + solve(index+1, prices, num+1, k, dp), solve(index+1, prices, num, k, dp));
        }

        return dp[index][num] = max(prices[index] + solve(index+1, prices, num+1, k, dp), solve(index+1, prices, num, k, dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        // we can sell and buy k times so our num can go upto 0 -> 2k-1
        // even --> buy
        // odd --> sell
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return solve(0, prices, 0, k, dp);
    }
};


// Tabulation 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // we can sell and buy k times so our num can go upto 0 -> 2k-1
        // even --> buy
        // odd --> sell
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

        for(int index = n-1; index >= 0; index--){
            for(int num = 2*k-1; num >= 0; num--){
                if(num % 2 == 0){ // buy
                    dp[index][num] = max(-prices[index] + dp[index+1][num+1], dp[index+1][num]);
                }
                else{ // sell
                    dp[index][num] = max(prices[index] + dp[index+1][num+1], dp[index+1][num]);
                }
            }
        }

        return dp[0][0];
    }
};

// Best solution (same as previous one just used for k transactions)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k, -prices[0]);
        vector<int> sell(k, 0);

        for(int i = 1; i<prices.size(); i++){
            int price = prices[i];
            buy[0] = max(buy[0], -price);
            sell[0] = max(sell[0], buy[0] + price);
            for(int j = 1; j<k; j++){
                buy[j] = max(buy[j], sell[j-1] - price);
                sell[j] = max(sell[j], buy[j] + price); 
            }
        }

        return sell[k-1];
    }
};
