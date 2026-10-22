#include<iostream> 
using namespace std;

// Spiral Traversal of a matrix
// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int firstRow = 0;
        int lastRow = n-1;
        int firstCol = 0;
        int lastCol = m-1;

        while(firstRow <= lastRow && firstCol <= lastCol){
            // printing the first row
            for(int i = firstCol; i<=lastCol; i++){
                ans.push_back(matrix[firstRow][i]);
            }
            firstRow++;

            // print the last column
            for(int i = firstRow; i<= lastRow; i++){
                ans.push_back(matrix[i][lastCol]);
            }
            lastCol--;

            // print the last row
            for(int i = lastCol; i>= firstCol && firstRow <= lastRow; i--){
                ans.push_back(matrix[lastRow][i]);
            }
            lastRow--;

            // print the first column
            for(int i = lastRow; i>=firstRow && firstCol <= lastCol; i--){
                ans.push_back(matrix[i][firstCol]);
            }
            firstCol++;
        }

        return ans;
    }
};

