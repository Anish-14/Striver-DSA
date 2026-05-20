#include<iostream>
using namespace std;

//  partition equal subset sum
// https://leetcode.com/problems/partition-equal-subset-sum/


// Recursion + Memoization
class Solution {
public:
    bool solve(int index, vector<int> &nums, int target, vector<vector<int>> &dp){
        if(index < 0){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool notTake = solve(index-1, nums, target, dp);
        bool take = false;
        if(nums[index] <= target){
            take = solve(index-1, nums, target-nums[index], dp);
        }

        return dp[index][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }

        if(sum % 2 == 1)    return 0;

        vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
        // the question comes down to finding a subsequence of sum "sum/2".
        return solve(n-1, nums, sum/2, dp);     
    }
};


// Tabulation 
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }

        if(sum % 2 == 1)    return 0;
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        // the question comes down to finding a subsequence of sum "sum/2".

        // base cases
        for(int i = 0; i<n; i++)    dp[i][0] = 1;
        if(nums[0] <= target){
            dp[0][nums[0]] = 1;
        }

        for(int i = 1; i<n; i++){
            for(int tar = 1; tar<=target; tar++){
                bool notTake = dp[i-1][tar];
                bool take = false;
                if(nums[i] <= tar){
                    take = dp[i-1][tar-nums[i]];
                }
                dp[i][tar] = notTake || take;
            }
        }

        return dp[n-1][target];  
    }
};
