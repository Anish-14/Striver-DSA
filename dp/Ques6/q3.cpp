#include<iostream>
using namespace std;

// Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp = matrix;

        // preparing our dp matrix
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(dp[i][j] == 0)   continue;
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }

        // now the number of squares will be simply the summation of the values of the dp array
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ans += dp[i][j];
            }
        }

        return ans;
    }
};