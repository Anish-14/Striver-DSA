#include<iostream>
using namespace std;

// next greater element
// https://leetcode.com/problems/next-greater-element-i/description/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;

        for(int i = 0; i<nums2.size(); i++){
            while(!st.empty()){
                int top = st.top();
                if(nums2[i] > top){
                    mp[top] = nums2[i];
                    st.pop();  
                } 
                else{
                    break;
                }
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int i = 0; i<nums1.size(); i++){
            if(mp.find(nums1[i]) == mp.end()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(mp[nums1[i]]);
            }
        }

        return ans;
    }
};