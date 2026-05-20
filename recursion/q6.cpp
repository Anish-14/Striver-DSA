// Subsets 2
// https://leetcode.com/problems/subsets-ii/


#include<iostream>
using namespace std;
class Solution {
public:

    void solve(vector<vector<int>> &ans, vector<int>& nums, vector<int>& temp, int index) {
        ans.push_back(temp); // push as soon as you reach this node (before branching)

        for (int i = index; i < nums.size(); i++){
            if (i > index && nums[i] == nums[i - 1]) continue; // skip duplicates
            temp.push_back(nums[i]);
            solve(ans, nums, temp, i + 1);
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, nums, temp, 0);

        return ans;
    }
};


