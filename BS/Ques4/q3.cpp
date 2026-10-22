#include<iostream>
using namespace std;

// Find a Peak Element II
// https://leetcode.com/problems/find-a-peak-element-ii/description/

class Solution {
public:
    int maxi(vector<vector<int>>& mat, int m, int n) {
        int maxim = mat[0][m];
        int ind = 0;
        for (int i = 1; i < n; i++) {
            if (mat[i][m] > maxim) {
                ind = i;
                maxim = mat[i][m];
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m-1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int ind = maxi(mat, mid, n);
            
            int left = (mid == 0 ? -1 : mat[ind][mid - 1]);
            int right = (mid == m - 1 ? -1 : mat[ind][mid + 1]);
            int val = mat[ind][mid];

            if (val > left && val > right)
                return {ind, mid};
            else if (val <= left)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {-1, 1};
    }
};
