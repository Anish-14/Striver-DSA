#include<iostream>
#include<vector>
using namespace std;

// Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

// We can find nse and pse and then calculate the max rectangular area.

// the best solution --> here we're storing the pse in the stack while traversing only
// the moment we encounter the nse we calculate the answer
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;      // will store the index in increasing order
        int maxi = 0;

        int i = 0;
        while(i < n){
            while(!st.empty() && heights[st.top()] > heights[i]){
                // now we'll calculate
                int current = st.top();
                st.pop();

                int pse = st.empty() ? -1 : st.top();

                int area = heights[current]*(i-pse-1);
                maxi = max(maxi, area);
            }
            st.push(i);
            i++;
        }

        // now calculate the answer for the remaining ones
        while(!st.empty()){
            int current = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();

            // nse will be n for all the remaining one
            int area = heights[current]*(n - pse - 1);
            maxi = max(maxi, area);
        }

        return maxi;
    }   
};



