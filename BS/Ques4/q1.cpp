#include<iostream>
using namespace std;

// Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s = 0, e = m*n-1;

        while(s <= e){
            int mid = s + (e-s)/2;
            int i = mid/n, j = mid%n;
            int val = matrix[i][j];

            if(val == target){
                return true;
            }
            else if(val > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return false;
    }
};