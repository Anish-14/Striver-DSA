#include<iostream>
using namespace std;

// print all permutations
// https://leetcode.com/problems/permutations/description/

class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index, int n){
        // base case
        if(index == n){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i<n; i++){
            swap(nums[index], nums[i]);
            solve(nums, ans, index+1, n);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        solve(nums, ans, 0, n);

        return ans;
    }
};