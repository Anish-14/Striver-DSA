#include<iostream>
using namespace std;

// Number of Longest Increasing Subsequence
// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> dp(n, {1,1});    // value, its freq
        unordered_map<int, int> mp;         // will store the subsequences and its freq 

        int maxi = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(1 + dp[j].first == dp[i].first){
                        dp[i].second += dp[j].second;       // add this paths freq to our current count
                    }
                    else if(1 + dp[j].first > dp[i].first){
                        dp[i].first = 1 + dp[j].first;      // update your max length
                        dp[i].second = dp[j].second;        // and its freq too
                    }
                }
            }
            // we are saying that for this length this is the freq and it to the map as 
            // it can be that other indexes also might give us the same length subsequence

            mp[dp[i].first] = mp[dp[i].first] + dp[i].second;   

            if(dp[i].first > maxi){
                maxi = dp[i].first;
            }
        }

        return mp[maxi];
    }
};




