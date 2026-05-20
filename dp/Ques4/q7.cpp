#include<iostream>
using namespace std;

// buy and sell stock 5
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/



// recursion + memo
class Solution {
public:
    // i --> day
    // t --> no. of transactions
    // state(representing what happened previously) --> 0,1,2 --> No transaction, bought earlier, sold earlier
    long long f(int i, int t, int state, vector<int> &prices, int k, vector<vector<vector<long long >>> &dp){
        if(i >= prices.size()){
            if(state == 0)  return 0;
            return -1e15;             // return a large negative number so that you tell that this is not possible
        }
        if(dp[i][t][state] != -1){
            return dp[i][t][state];
        }

        // do nothing, as we can always do nothing at each day
        long long ans = f(i+1, t, state, prices, k, dp);

        if(state == 0){ // we didn't buy anything before
            ans = max(ans, f(i+1, t, 1, prices, k, dp) - (long long)prices[i]);    // let's buy here
            ans = max(ans, f(i+1, t, 2, prices, k, dp) + (long long)prices[i]);    // let's sell here
        }
        else if(state == 1 && t < k){    // as transaction completed so we increased t
            ans = max(ans, f(i+1, t+1, 0, prices, k, dp) + (long long)prices[i]);     // let's sell here and tell'm we are free do anything now
        }
        else if(state == 2 && t < k){    // as transaction completed so we increased t
            ans = max(ans, f(i+1, t+1, 0, prices, k, dp) - (long long)prices[i]);    // let's buy here and tell'm we are free do anything now
        }

        return dp[i][t][state] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k+1, vector<long long>(3, -1)));
        return f(0, 0, 0, prices, k, dp);
    }
};


// Tabulation 
class Solution {
public:
    // i --> day
    // t --> no. of transactions
    // state(representing what happened previously) --> 0,1,2 --> No transaction, bought earlier, sold earlier
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(k+1, vector<long long>(3, 0)));
        // base case
        for(int i = 0; i<=k; i++){
            for(int j = 1; j<=2; j++){
                dp[n][i][j] = -1e15;
            }
        }

        for(int i = n-1; i>=0; i--){
            for(int t = k; t>=0; t--){
                for(int state = 2; state >= 0; state--){

                    // do nothing, as we can always do nothing at each day
                    long long ans = dp[i+1][t][state];

                    if(state == 0){ // we didn't buy anything before
                        ans = max(ans, dp[i+1][t][1] - (long long)prices[i]);    // let's buy here
                        ans = max(ans, dp[i+1][t][2] + (long long)prices[i]);    // let's sell here
                    }
                    else if(state == 1 && t < k){    // as transaction completed so we increased t
                        ans = max(ans, dp[i+1][t+1][0] + (long long)prices[i]);     // let's sell here and tell'm we are free do anything now
                    }
                    else if(state == 2 && t < k){    // as transaction completed so we increased t
                        ans = max(ans, dp[i+1][t+1][0] - (long long)prices[i]);    // let's buy here and tell'm we are free do anything now
                    }

                    dp[i][t][state] = ans;
                }
            }
        }

        return dp[0][0][0];
    }
};
