#include<iostream>
using namespace std;

// Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int left = 0;
        int ans = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0)    zeros++;
            if(zeros > k){
                while(left < nums.size() && nums[left] != 0){
                    left++;
                }
                left++;
                zeros--;
            }
            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};
