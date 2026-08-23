#include<iostream>
#include<vector>
using namespace std;

// Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 2*n-1; i>=0; i--){      // we extended the array to double its length hypothetically
            int index = i%n;
            while(!st.empty() && nums[index] >= st.top()){
                st.pop();
            }
            
            if(i < n){
                ans[i] = st.empty() ? -1 : st.top();
            }

            st.push(nums[index]);
        }

        return ans;
    }
};


