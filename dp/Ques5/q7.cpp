#include<iostream>
using namespace std;

// Burst Balloons
// https://leetcode.com/problems/burst-balloons/description/

// Recursion + Memo

// The idea here is to analyse this problem in reverse.
// focus on the last burst balloon, and then come back forming the array
// when last balloon will be burst then its right and left would be 1
// for the second last, this last balloon will be either left or right
// so in this sense we can calculate the value with actually monitoring which is the left and right element 
// that we need to take into our mind to multiply with
class Solution {
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        // base case
        if(i > j)   return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maxi = INT_MIN;
        // try to burst all possible ballons
        for(int k = i; k<=j; k++){
            int burst = nums[i-1]*nums[k]*nums[j+1] + solve(i, k-1, nums, dp) + solve(k+1, j, nums, dp);
            maxi = max(maxi, burst);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(1, n, nums, dp);               // the n represent the "n-1" the index now as we have added two more items in it
    }
};


// Tabulation 
class Solution {
public:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp){
        // base case
        if(i > j)   return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int maxi = INT_MIN;
        // try to burst all possible ballons
        for(int k = i; k<=j; k++){
            int burst = nums[i-1]*nums[k]*nums[j+1] + solve(i, k-1, nums, dp) + solve(k+1, j, nums, dp);
            maxi = max(maxi, burst);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i = n; i>=1; i--){
            for(int j = i; j<=n; j++){
                int maxi = INT_MIN;
                // try to burst all possible ballons
                for(int k = i; k<=j; k++){
                    int burst = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, burst);
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][n];
    }
};


