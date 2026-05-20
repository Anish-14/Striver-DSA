#include<iostream>
using namespace std;

// buy and sell stock 3
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/


// recursion + memo
class Solution {
public:
    int solve(int index, vector<int> &prices, int num, vector<vector<int>> &dp){
        if(index >= prices.size() || num >= 4){
            return 0;
        }
        if(dp[index][num] != -1){
            return dp[index][num];
        }

        if(num%2 == 0){     // buy
            return dp[index][num] = max(-prices[index] + solve(index+1, prices, num+1, dp), solve(index+1, prices, num, dp));
        }
        // sell
        return dp[index][num] = max(prices[index] + solve(index+1, prices, num+1, dp), solve(index+1, prices, num, dp));    
    }
    int maxProfit(vector<int>& prices) {
        // 0 and 2 --> the first and second buy respectively
        // 1 and 3 --> the first and second sell respectively
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return solve(0, prices, 0, dp);
    }
};

// Tabulation 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 0 and 2 --> the first and second buy respectively
        // 1 and 3 --> the first and second sell respectively
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (5, 0));

        for(int index = n-1; index >= 0; index--){
            for(int num = 3; num >= 0; num--){
                if(num % 2 == 0){
                    dp[index][num] = max(-prices[index] + dp[index+1][num+1], dp[index+1][num]);
                }
                else{
                    dp[index][num] = max(prices[index] + dp[index+1][num+1], dp[index+1][num]);
                }
            }
        }

        return dp[0][0];
    }
};


// Best solution (Not intuitive though)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0];
        int sell2 = 0;

        for(int i = 1; i<prices.size(); i++){
            int price = prices[i];
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }
};



