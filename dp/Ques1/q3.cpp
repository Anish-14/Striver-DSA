#include<iostream>
using namespace std;

// Max Sum without Adjacents
// https://www.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1


// Recursion 
class Solution {
  public:
    int solve(vector<int> &arr, int index){
        if(index >= arr.size()){
            return 0;
        }
        
        return max(0+solve(arr, index+1), arr[index] + solve(arr, index+2));
    }
    int findMaxSum(vector<int>& arr) {
        return solve(arr, 0);
    }
};

// Memo
class Solution {
  public:
    int solve(vector<int> &arr, int index, vector<int> &dp){
        if(index >= arr.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        
        return dp[index] = max(0+solve(arr, index+1, dp), arr[index] + solve(arr, index+2, dp));
    }
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return solve(arr, 0, dp);
    }
};

// tabulation 
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+2, 0);     // dp[n] = dp[n+1] = 0 as base
        for(int i = n-1; i>=0; i--){
            dp[i] = max(dp[i+1], arr[i] + dp[i+2]);
        }
        
        return dp[0];
    }
};

// Space Optimisation
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        int one = 0;    // dp[i+1]
        int two = 0;    // dp[i+2]
        int ans = 0;
        for(int i = n-1; i>=0; i--){
            ans = max(one, arr[i] + two);
            two = one;
            one = ans;
        }
        
        return one;
    }
};



