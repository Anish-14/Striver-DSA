#include<iostream>
using namespace std;

// Search in Rotated Sorted Array II
// http://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
// it can have duplicate values

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;
            if(nums[mid] == target){
                return true;
            }

            // we can do this as well and comment the below if condition
            // if(nums[mid] == nums[left] && nums[mid] == nums[right]){
            //     left++;
            //     right--;
            //     continue;
            // }
            if(nums[mid] == nums[left]){
                left++;
                continue;
            }

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(nums[right] >= target && target > nums[mid]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

