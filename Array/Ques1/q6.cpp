#include<iostream> 
using namespace std;

// Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0, count = 0;
        unordered_map<int,int> sumCount;
        sumCount[0] = 1;

        for(int i = 0; i<nums.size(); i++){
            total += nums[i];

            if(sumCount.find(total - k) != sumCount.end()){
                count += sumCount[total-k];
            }

            sumCount[total]++; 
        }

        return count;
    }
};


