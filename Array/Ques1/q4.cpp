#include<iostream> 
using namespace std;

// Missing Number
// https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int TotalSum = (n*(n+1))/2;

        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }

        return TotalSum - sum;
    }
};