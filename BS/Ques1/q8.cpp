#include<iostream>
using namespace std;

// Find Minimum in Rotated Sorted Array
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[n-1] >= nums[0]){
            return nums[0];
        }

        int s = 0;
        int e = n-1;

        while(s < e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= nums[0]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }

        return nums[s];
    }
};
