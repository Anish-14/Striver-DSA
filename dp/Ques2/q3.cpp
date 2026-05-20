#include<iostream>
using namespace std;

// Target Sum
// https://leetcode.com/problems/target-sum/
// this problem can also be seen as "partition the array such that the difference between them is k"
// Very good problem to give you idea of how to handle negative indices.


// Recursion
class Solution {
public:
    int solve(int index, vector<int> &nums, int target){
        if(index < 0){
            if(target == 0) return 1;
            return 0;
        }

        int minus = solve(index-1, nums, target+nums[index]);
        int plus = solve(index-1, nums, target-nums[index]);
        
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums.size() - 1, nums, target);
    }
};


// memoization  (here as target can go negative therefore we used map instead of vector for dp)
class Solution {
public:
    int solve(int index, vector<int> &nums, int target,vector<unordered_map<int,int>> &dp){
        if(index < 0){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[index].count(target)){
            return dp[index][target];
        }

        int minus = solve(index-1, nums, target+nums[index], dp);
        int plus = solve(index-1, nums, target-nums[index], dp);
        
        return dp[index][target] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        return solve(nums.size() - 1, nums, target, dp);
    }
};


// Tabulation 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        int offset = sum;
        int range = 2*offset + 1;

        if(abs(target) > sum)    return 0;

        vector<vector<int>> dp(n, vector<int>(range, 0));
        dp[0][nums[0] + offset] = 1;           // the "+=" is necessary even though we're updating the first value as
        dp[0][-nums[0] + offset] += 1;          // let's say nums[0] == 0 then it should be count two times and "+=" ensures it
 
        for(int i = 1; i<n; i++){
            for(int s = -sum; s<=sum; s++){
                // if we can reach this sum previously then do the plus minus thing
                if(dp[i-1][s + offset] > 0){
                    int prev_ways = dp[i-1][s+offset];
                    if(s + nums[i] <= sum){     // safety check (not needed though as we've handled it already)
                        dp[i][s+nums[i]+offset] += prev_ways;
                    }
                    if(s - nums[i] >= -sum){
                        dp[i][s-nums[i]+offset] += prev_ways;
                    }
                }
            }
        }

        return dp[n-1][target+offset];
    }
};
