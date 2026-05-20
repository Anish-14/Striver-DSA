#include<iostream>
using namespace std;

// Largest histogram area
// https://leetcode.com/problems/largest-rectangle-in-histogram/


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxi = 0;
        st.push(0);
        int i = 1;

        while(i < heights.size()){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = st.top();
                st.pop();

                int prev = st.empty()? -1 : st.top();
                int total = heights[ele]*(i-prev-1);
                maxi = max(maxi, total);
            }
            st.push(i);
            i++;
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();

            int prev = st.empty()? -1 : st.top();
            int total = heights[ele]*(heights.size() - prev - 1);
            maxi = max(maxi, total);
        }

        return maxi;
    }
};


