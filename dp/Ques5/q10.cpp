#include<iostream>
using namespace std;

// Partition Array for Maximum Sum
// https://leetcode.com/problems/partition-array-for-maximum-sum/description/

// recur + memo
class Solution {
public:
    int solve(int i, int k, vector<int> &arr, vector<int> &dp){
        // base cases
        if(i == arr.size()) return 0;
        if(dp[i] != -1){
            return dp[i];
        }

        int maxi = INT_MIN;
        int maxVal = 0;
        // try partitions
        for(int j = i; j<i+k && j<arr.size(); j++){
            maxVal = max(maxVal, arr[j]);
            int val = maxVal*(j-i+1) + solve(j+1, k, arr, dp);
            maxi = max(maxi, val);
        }

        return dp[i] = maxi;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, k, arr, dp);
    }
};

// Tabulation 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int i = n-1; i>=0; i--){
            int maxi = INT_MIN;
            int maxVal = 0;
            // try partitions
            for(int j = i; j<i+k && j<arr.size(); j++){
                maxVal = max(maxVal, arr[j]);
                int val = maxVal*(j-i+1) + dp[j+1];
                maxi = max(maxi, val);
            }

            dp[i] = maxi;
        }

        return dp[0];
    }
};
