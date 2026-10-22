#include<iostream>
using namespace std;

// Single Number II
// https://leetcode.com/problems/single-number-ii/description/

// brute force is by using a map 

// bit method
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<32; i++){
            int sum = 0;
            // count how many nums have ith bit as 1
            for(int j = 0; j<n; j++){
                sum += (nums[j] >> i) & 1;
            }

            // if the number of set bit is 3n+1 then the single number has a bit at this place
            sum = sum % 3;
            if(sum == 1)    ans = ans | (1 << i);
        }

        return ans;
    }
};


// another solution which is better than the above one in average or smaller n values
// O(NlogN + N/3) && O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 1; i<n; i+=3){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }

        return nums[n-1];
    }
};


// best solution & not intuitive
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i = 0; i<nums.size(); i++){
            ones = ((ones^nums[i]) & ~twos);
            twos = ((twos^nums[i]) & ~ones);
        }

        return ones;
    }
};
