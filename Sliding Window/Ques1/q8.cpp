#include<iostream>
using namespace std;

// Binary Subarrays With Sum
// https://leetcode.com/problems/binary-subarrays-with-sum/description/

// Beautiful Problem
class Solution {
public:
    int lessThanGoal(vector<int> &nums, int goal){
        if(goal < 0)    return 0;

        int n = nums.size();
        int l = 0, i = 0, cnt = 0;
        int sum = 0;

        for(; i<n; i++){
            sum += nums[i];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }

            cnt += i-l+1;
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (lessThanGoal(nums, goal) - lessThanGoal(nums, goal-1));
    }
};
