#include<iostream>
using namespace std;

// Subarrays with K Different Integers
// https://leetcode.com/problems/subarrays-with-k-different-integers/description/

class Solution {
public:
    int lessThan(vector<int> &nums, int k){
        int n = nums.size();
        int l = 0, cnt = 0, i = 0;
        unordered_map<int,int> freq;

        for(int i = 0; i<n; i++){
            freq[nums[i]]++;

            while(freq.size() > k){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0){
                    freq.erase(nums[l]);
                }
                l++;
            }

            cnt += i-l+1;
        }

        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (lessThan(nums, k) - lessThan(nums, k-1));
    }
};