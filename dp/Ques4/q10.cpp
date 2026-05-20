#include<iostream>
using namespace std;

// Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/description/


// Recur + memo
class Solution {
public:
    int solve(int index, int prev_index, vector<int> nums, vector<vector<int>> &dp){
        // base cases
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index][prev_index + 1] != -1){
            return dp[index][prev_index + 1];
        }

        // option 1 : it is always possible to skip the current element
        int result = solve(index+1, prev_index, nums, dp);

        // option 2 : include this number in the subsequence only if it is valid
        if(prev_index == -1 || nums[index] > nums[prev_index]){
            result = max(result, 1 + solve(index+1, index, nums, dp));
        }

        return dp[index][prev_index + 1] = result;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(0, -1, nums, dp);
    }
};


// Tabulation 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; i--){      // i == n is the base case
            for(int j = n; j>= 0; j--){
                int res = dp[i+1][j];
                if(j == 0 || nums[i] > nums[j-1]){
                    res = max(res, 1 + dp[i+1][i+1]);   // as we are using j --> index+1 everywhere so here also we'll add +1;
                }
                dp[i][j] = res;
            }
        }

        return dp[0][0];
    }
};



// binary search solution (best solution for this problem && is intuitvie as well)
class Solution {
public:
    int findIndex(vector<int> &res, int target){
        int left = 0, right = res.size()-1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(res[mid] == target){
                return mid;
            }
            else if(res[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;        // this is a vector and we will store the values in increasing order in it and will compare with the last value 
        for(int i = 0; i<nums.size(); i++){
            if(res.empty() || res.back() < nums[i]){    // if we get a number larger than our last number than we put it in our vec
                res.push_back(nums[i]);
            }
            else{   // if we get some smaller value then we go find the index where it should fit and put it there, this way we can include all the possibilities.
                int index = findIndex(res, nums[i]);
                res[index] = nums[i];
            }
        }

        return res.size();
    }
};
