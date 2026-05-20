// Subsets 
// https://leetcode.com/problems/subsets/


#include<iostream>
using namespace std;
class Solution {
public:
    // inclusion exclusion
    void solve(vector<vector<int>> &ans, vector<int> temp, vector<int> & nums, int n){
        if(n == nums.size()){
            ans.push_back(temp);
            return;
        }

        // pehle include karna rather than pehle exclude karna will give you a low runtime
        // however both the answers are correct. The reason for it is that temp's memory 
        // grows earlier giving some efficiency.

        // include
        temp.push_back(nums[n]);
        solve(ans, temp, nums, n+1);

        temp.pop_back();
        // exclude
        solve(ans, temp, nums, n+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans,temp,nums,0);

        return ans;
    }
};




