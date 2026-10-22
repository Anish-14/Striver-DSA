#include<iostream>
using namespace std;

// Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/

// recur + memo
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (matrix[i][j] == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int top = solve(i - 1, j, matrix, dp);
        int left = solve(i, j - 1, matrix, dp);
        int diag = solve(i - 1, j - 1, matrix, dp);

        return dp[i][j] = 1 + min(top, min(left, diag));
    }

    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans += solve(i, j, matrix, dp);
            }
        }

        return ans;
    }
};


// Tabulation
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


// space optimised
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        curr[j] = 1;
                    } else {
                        curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
                    }
                    ans += curr[j];
                }
            }
            prev = curr;
        }

        return ans;
    }
};


// we can further solve it in one array as well
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m, 0);
        int ans = 0;
        int diag = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int temp = dp[j];
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[j] = 1;
                    } else {
                        dp[j] = 1 + min(dp[j], min(dp[j - 1], diag));
                    }
                    ans += dp[j];
                } else {
                    dp[j] = 0;
                }
                diag = temp;
            }
        }

        return ans;
    }
};