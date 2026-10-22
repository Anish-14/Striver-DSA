#include<iostream> 
using namespace std;

// 3 Sum
// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O(n^2) TC
        // sort it --> O(nlogn)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i<n; i++){
            while(i != 0 && i<n && nums[i] == nums[i-1]){
                i++;
            }
            int s = i+1;
            int e = n-1;
            while(s < e){
                int sum = nums[i];
                sum += nums[s];
                sum += nums[e];
                if(sum == 0){
                    ans.push_back({nums[i], nums[s], nums[e]});
                    
                    while(s<e && nums[s] == nums[s+1]){
                        s++;
                    }
                    while(s<e && nums[e-1] == nums[e]){
                        e--;
                    }
                    s++;
                    e--;
                }
                else if(sum < 0){
                    s++;
                }
                else {
                    e--;
                }
            }
        }

        return ans;
    }
};