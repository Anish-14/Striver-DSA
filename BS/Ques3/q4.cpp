#include<iostream>
#include<numeric>
using namespace std;

// Split Array Largest Sum
// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public: 
    bool isPossible(vector<int>& nums, int k, int max_sum){
        int sum = 0, count = 1;
        for(int i = 0; i<nums.size(); i++){
            // subarray ka sum agar max_sum se kam hai to usme bharte jaao
            if(sum + nums[i] <= max_sum){
                sum += nums[i];
            }
            else{   
                // jaise hi subarray ki capacity reach ho gyi then move up to
                // the next subarray
                sum = nums[i];
                count++;    // increase the count as you've moved a subarray
                if(count > k)   // if count exceeds the number "k" then It return false
                    return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int min = *max_element(nums.begin(), nums.end());   // fun to get the max element
        int max = accumulate(nums.begin(), nums.end(),0);   // fun to get the sum
        // answer inhi dono ke beech lie karega, so let's use binary search
        while(min < max){
            int mid = min + (max - min)/2;
            if(isPossible(nums,k , mid)){ 
                // agar ye answer possible hai then let's search for smaller one
                max = mid;
            }
            else{
                min = mid+1;
            }
        }
        return min;
    }
};




