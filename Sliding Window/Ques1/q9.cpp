#include<iostream>
using namespace std;

// Count Number of Nice Subarrays
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
    int oddLessThan(vector<int> &nums, int k){
        if(k < 0)   return 0;
        int n = nums.size();
        int l = 0, i = 0, cnt = 0;
        int odd = 0;

        for(; i<n; i++){
            if(nums[i] & 1){
                odd++;
            }

            while(odd > k){
                if(nums[l] & 1){
                    odd--;
                }
                l++;
            }

            cnt += i-l+1;
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (oddLessThan(nums, k) - oddLessThan(nums, k-1));
    }
};