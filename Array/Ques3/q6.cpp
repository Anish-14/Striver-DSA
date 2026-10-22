#include<iostream>
using namespace std;

// Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    int getMax(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }
    int maxProduct(vector<int>& nums) {
        int res = getMax(nums);
        // int res = INT_MIN;
        int curMax = 1, curMin = 1;

        for(int i = 0; i<nums.size(); i++){
            int temp = curMax*nums[i];
            curMax = max({nums[i], temp, curMin*nums[i]});
            curMin = min({nums[i], temp, curMin*nums[i]});

            res = max(res, curMax);
        }

        return res;
    }
};


