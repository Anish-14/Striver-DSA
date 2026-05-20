#include<iostream>
using namespace std;

// 0/1 knapsack
// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// Recurison + Memoization 
class Solution {
  public:
    int solve(int index, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp){
        if(index == 0){
            if(wt[index] <= W)  return val[index];
            return 0;
        }
        if(dp[index][W] != -1){
            return dp[index][W];
        }
        // notTake
        int notTake = solve(index-1, W, val, wt, dp);
        int take = 0;
        if(wt[index] <= W){
            take = val[index] + solve(index-1, W-wt[index], val, wt, dp);
        }
        
        return dp[index][W] = max(take , notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solve(n-1, W, val, wt, dp);
    }
};


// Tabulation 
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        // prepare the base cases
        for(int w = 0; w<=W; w++){
            if(w >= wt[0]) 
                dp[0][w] = val[0];
        }
        
        for(int i = 1; i<n; i++){
            for(int weight = 0; weight <= W; weight++){
                int notTake = dp[i-1][weight];
                int take = 0;
                if(wt[i] <= weight){
                    take = val[i] + dp[i-1][weight - wt[i]];
                }
                
                dp[i][weight] = max(take, notTake);
            }
        }
        
        
        return dp[n-1][W];
    }
};


