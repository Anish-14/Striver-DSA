#include<iostream>
using namespace std;

// Single Element in a Sorted Array
// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = nums.size() - 1;

        while(s <= e){
            int mid = s + (e-s)/2;
            // cout<<"mid "<<mid<<endl;

            int left = -1;
            int right = -1;
            if(mid-1 >= 0)  left = nums[mid-1];
            if(mid+1 < n)   right = nums[mid+1];

            if(nums[mid] != left && nums[mid] != right){
                return nums[mid];
            }
            else if(nums[mid] == left && (e-mid) % 2 == 0){
                e = mid-2;
            }
            else if(nums[mid] == right && (mid-s) % 2 == 1){
                e = mid - 1;
            }
            else if(nums[mid] == left && (e-mid) % 2 == 1){ 
                s = mid + 1;
            }
            else{
                s = mid+2;
            }
        }

        return -1;
    }
};
