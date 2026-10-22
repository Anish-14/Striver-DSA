#include<iostream>
using namespace std;

// Median in a Row-Wise Sorted Matrix
// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

class Solution {
  public:
    int find_max_min(vector<vector<int>>&mat, bool big){
        int m = mat.size();
        int n = mat[0].size();
        
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i = 0; i<m; i++){
            maxi = max(maxi, mat[i][n-1]);
            mini = min(mini, mat[i][0]);
        }
        
        return (big)?maxi:mini;
    }
    
    // do this using lower_bound to make it also O(logn)
    int nums_less_equal(vector<vector<int>>&mat, int mid){
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;
        for(int i = 0; i<m ; i++){
            if(mat[i][0] > mid) continue;
            
            for(int j = 0; j<n; j++){
                if(mat[i][j] <= mid) cnt++;
            }
        }
        return cnt;
    }
    
    int median(vector<vector<int>> &mat) {
        // code here
        int m = mat.size();
        int n = mat[0].size();
        
        int l = find_max_min(mat, false), r = find_max_min(mat, true);
        int req = (m*n)/2;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums_less_equal(mat, mid) > req) r = mid-1;
            else l = mid + 1;
        }
        return l;
    }
};



