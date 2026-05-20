
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