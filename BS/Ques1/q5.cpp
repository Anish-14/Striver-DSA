#include<iostream>
using namespace std;

// Find First and Last Position of Element in Sorted Array
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

// in the worst case this is a linear complexity problem
// we can use upper and lower bound to solve this problem --> 
// if lower bound if out of range or if it is > x then return {-1,-1} else return lower_bound, upper_bound-1
// this sol is guaranteed to be in log(n) complexity
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        int n = nums.size();

        int s = 0;
        int e = n - 1;

        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                // first index
                int i = mid;
                while(i - 1 >= 0 && nums[i-1] == target){
                    i--;
                }
                ans[0] = i;

                // second index;
                i = mid;
                while(i + 1 < n && nums[i+1] == target){
                    i++;
                }
                ans[1] = i;

                break;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return ans;
    }
};