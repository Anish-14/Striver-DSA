#include<iostream>
using namespace std;

// Partition DP

// Matrix Chain Multiplication
// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// Recursion Approach
class Solution {
  public:
    int solve(int i, int j, vector<int> &arr){
        // base case
        if(i == j)  return 0;
            
        int mini = 1e9;
        // trying all the partitions
        for(int k = i; k<=j-1; k++){
            // the multiplication is the matrix multiplication after the partition comes back and this is the 
            // number of operations for the final matrix multiplication
            int val = arr[i-1]*arr[k]*arr[j] + solve(i, k, arr) + solve(k+1, j, arr);
            mini = min(mini, val);
        }

        return mini;        
    }
    int matrixMultiplication(vector<int> &arr) {
        // the (i,j) represent the part that is getting multiplied
        int n = arr.size();
        return solve(1, n-1, arr);
    }
};


// Memoization 
class Solution {
  public:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        // base case
        if(i == j)  return 0;
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
            
        int mini = 1e9;
        // trying all the partitions
        for(int k = i; k<=j-1; k++){
            int val = arr[i-1]*arr[k]*arr[j] + solve(i, k, arr, dp) + solve(k+1, j, arr, dp);
            mini = min(mini, val);
        }

        return dp[i][j] = mini;        
    }
    int matrixMultiplication(vector<int> &arr) {
        // the (i,j) represent the part that is getting multiplied
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n-1, arr, dp);
    }
};


// Tabulation 
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // the (i,j) represent the part that is getting multiplied
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // base case has already been initialized as it was zero only
        // we are traversing only the half of the dp matrix as you can see
        // the base case was in such a way that we were only using half of the values
        for(int i = n-1; i>=1; i--){
            for(int j = i; j<n; j++){
                if(j == i)  continue;
                int mini = 1e9;
                // trying all the partitions
                for(int k = i; k<=j-1; k++){
                    int val = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, val);
                }
                
                dp[i][j] = mini;
            }
        }
        
        return dp[1][n-1];
    }
};


