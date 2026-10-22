#include<iostream> 
using namespace std;

// Rotate Matrix/Image by 90 Degrees 
// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void reverse(vector<vector<int>> &matrix, int row){
        int nCol = matrix[row].size();
        int s = 0;
        int e = nCol-1;

        while(s < e){
            swap(matrix[row][s], matrix[row][e]);
            s++;
            e--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        // swap all the rows first
        for(int i = 0; i<matrix.size(); i++){
            reverse(matrix, i);
        }

        int n = matrix.size();
        int m = matrix[0].size();


        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<n-1-i; j++){
                swap(matrix[i][j], matrix[n-1-j][n-1-i]);
            }
        }
    }
};


