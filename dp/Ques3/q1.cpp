#include<iostream>
using namespace std;

// Unbounded knapsack
// https://www.naukri.com/code360/problems/unbounded-knapsack_1215029?leftPanelTabValue=PROBLEM


// Recursion + Tabulation
int solve(int index, vector<int> &val, vector<int>&wt, int capacity, vector<vector<int>> &dp){
        if(index == 0){
            if(wt[index] == 0)  return 0;
            
            int num = capacity / wt[index];
            return num * val[index];
        }
        if(dp[index][capacity] != -1){
            return dp[index][capacity];
        }
        
        int notTake = solve(index-1, val, wt, capacity, dp);
        int take = 0;
        if(wt[index] <= capacity){
            take = val[index] + solve(index, val, wt, capacity - wt[index], dp);
        }
        
        return dp[index][capacity] = max(notTake, take);
    }
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
        
    return solve(n-1, profit, weight, w, dp);
}




// Tabulation
int unboundedKnapsack(int n, int capacity, vector<int> &val, vector<int> &wt){
    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        
    // base case
    for(int cap = 0; cap <= capacity; cap++){
        int num = cap/wt[0];
        dp[0][cap] = num * val[0];
    }
    
    for(int index = 1; index < n; index++){
        for(int cap = 0; cap <= capacity; cap++){
            int notTake = dp[index-1][cap];
            int take = 0;
            if(wt[index] <= cap){
                take = val[index] + dp[index][cap - wt[index]];
            }
            
            dp[index][cap] = max(notTake, take);
        }
    }
    
    return dp[n-1][capacity];
}

