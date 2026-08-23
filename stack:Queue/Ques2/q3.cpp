#include<iostream>
#include<vector>
using namespace std;

// Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
public:
    int getArea(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        int i = 0;
        while(i < n){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int currIdx = st.top();
                st.pop();

                int pse = st.empty() ? -1 : st.top();

                int area = heights[currIdx]*(i - pse - 1);
                maxArea = max(maxArea, area);
            }
            st.push(i);
            i++;
        }

        while(!st.empty()){
            int currIdx = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();

            int area = heights[currIdx]*(n - pse - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> heights(m, 0);

        // traversing the rows
        for(int i = 0; i<n; i++){
            // create the current heights array
            for(int j = 0; j<m; j++){
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }

            // now I want to get the area for ths particular heights array
            int area = getArea(heights);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};