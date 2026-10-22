#include<iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm=codolio
// Median in a Row-Wise Sorted Matrix

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


// better, Uses BS in searching as well
class Solution {
  public:
    int get_max_min(vector<vector<int>> &mat, bool big){
        int n = mat.size();
        int m = mat[0].size();
        int maxi = INT_MIN, mini = INT_MAX;
        
        for(int i = 0; i<n; i++){
            maxi = max(maxi, mat[i][m-1]);
            mini = min(mini, mat[i][0]);
        }
        
        return big ? maxi : mini;
    }
    
    int upper_bound(vector<int> &arr, int target){
        int s = 0, e = arr.size()-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid] <= target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }    
        
        return s;
    }
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int s = get_max_min(mat, false);
        int e = get_max_min(mat, true);
        
        int half = (m*n)/2;
        // binary search to find the median
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            int lessThanEqualMid = 0;
            for(int i = 0; i<n; i++){
                lessThanEqualMid += upper_bound(mat[i], mid);
            }
            
            if(lessThanEqualMid <= half){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        
        return s;
    }
};



