#include<iostream>
using namespace std;

// House Robber
// https://leetcode.com/problems/house-robber/

// space optimized solution directly as it is similar to the Q3
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        int ans = max(prev, prev2);
        
        for(int i = 2; i<n; i++){
            ans = max(prev, nums[i] + prev2);
            prev2 = prev;
            prev = ans;
        }

        return ans;
    }
};



