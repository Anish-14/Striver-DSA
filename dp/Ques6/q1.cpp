#include<iostream>
using namespace std;

// Largest histogram area
// https://leetcode.com/problems/largest-rectangle-in-histogram/

// Recursion + memo
// this is the very basic method which we think as well
class Solution {
    // Memoization arrays
    vector<int> memoLeft;
    vector<int> memoRight;

    int solveLeft(int i, vector<int>& heights) {
        if (i == 0) return -1; // Base case: no element to the left
        if (memoLeft[i] != -2) return memoLeft[i];

        int p = i - 1;
        // DP Jump: skip bars that are >= heights[i]
        while (p >= 0 && heights[p] >= heights[i]) {
            p = solveLeft(p, heights);               // Jump directly to the next smaller element's index
        }

        return memoLeft[i] = p;
    }

    int solveRight(int i, vector<int>& heights, int n) {
        if (i == n - 1) return n; // Base case: no element to the right
        if (memoRight[i] != -2) return memoRight[i];

        int p = i + 1;
        // DP Jump: skip bars that are >= heights[i]
        while (p < n && heights[p] >= heights[i]) {
            p = solveRight(p, heights, n); // Jump directly to the next smaller element's index
        }

        return memoRight[i] = p;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        memoLeft.assign(n, -2);
        memoRight.assign(n, -2);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int l = solveLeft(i, heights);
            int r = solveRight(i, heights, n);
            int area = heights[i] * (r - l - 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};



// Tabulation 
// this the left and right array solution only where we keep track of the left element with lesser height and 
// similarly for the right one
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> left(n);  // left[i]: index of first element to left strictly smaller than heights[i]
        vector<int> right(n); // right[i]: index of first element to right strictly smaller than heights[i]

        // 1. Fill left DP table (Left to Right)
        left[0] = -1; // Base case
        for (int i = 1; i < n; i++) {
            int p = i - 1;
            // Jump to previous smaller element using already computed DP values
            while (p >= 0 && heights[p] >= heights[i]) {
                p = left[p];
            }
            left[i] = p;
        }

        // 2. Fill right DP table (Right to Left)
        right[n - 1] = n; // Base case
        for (int i = n - 2; i >= 0; i--) {
            int p = i + 1;
            // Jump to next smaller element using already computed DP values
            while (p < n && heights[p] >= heights[i]) {
                p = right[p];
            }
            right[i] = p;
        }

        // 3. Calculate max area using the DP boundaries
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};









// Optimal one using stacks
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

                int prev = st.empty() ? -1 : st.top();
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


