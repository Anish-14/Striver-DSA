#include<iostream>
using namespace std;

// best time to buy and sell stock 1
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0], profit = 0;
        for(int i = 0; i<n; i++){
            if(prices[i] < buy){
                buy = prices[i];
            }

            profit = max(profit, prices[i] - buy);
        }

        return profit;
    }
};