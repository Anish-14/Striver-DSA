#include<iostream>
using namespace std;

// Find the Smallest Divisor Given a Threshold
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/

class Solution {
public:
    int getMax(vector<int> &nums){
        int maxi = -1;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }
    int getSum(vector<int> &nums, int n, int mid){
        int sum = 0;
        for(int i = 0; i<n; i++){
            int ceil = (nums[i] + mid - 1)/mid;
            sum += ceil;
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = getMax(nums);
        int n = nums.size();

        int s = 1, e = maxi;

        while(s <= e){
            int mid = s + (e-s)/2;
            int val = getSum(nums, n, mid);

            if(val <= threshold){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return s;
    }
};
