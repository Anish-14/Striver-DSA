#include<iostream> 
using namespace std;

// Set Matrix Zeroes | O(1) Space Approach 
// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int firstRow = false;
        int firstCol = false;

        // Mark if the first row contains any zero
        for(int j = 0; j<m; j++){
            if(matrix[0][j] == 0){
                firstRow = true;
                break;
            }
        }

        // Do the same for the column as well
        for(int i = 0; i<n; i++){
            if(matrix[i][0] == 0){
                firstCol = true;
                break;
            }
        }

        // now mark all the rows and column if they contain any zero
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // now we'll fill the rows first
        for(int i = 1; i<n; i++){
            if(matrix[i][0] == 0){
                for(int j = 0; j<m; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        // similarly fil the cols as well
        for(int j = 1; j<m; j++){
            if(matrix[0][j] == 0){
                for(int i = 0; i<n; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        // Fill the first row if it needs to be filled
        if(firstRow){
            for(int j = 0; j<m; j++){
                matrix[0][j] = 0;
            }
        }

        // Similarly fill the first col as well
        if(firstCol){
            for(int i = 0; i<n; i++){
                matrix[i][0] = 0;
            }
        }

    }
};

