#include<iostream>
#include<vector>
using namespace std;

// Sliding Window Maximum
// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i<n; i++){
            // remove the first index of the window
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            // I want to now maintain the decreasing order in deque
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            // push the current element
            dq.push_back(i);

            // save answer only after the first window of k length is available
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

