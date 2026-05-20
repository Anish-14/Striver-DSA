#include<iostream>
using namespace std;

// Partitions with Given Difference
// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

class Solution {
  public:
   int mod = 1e9 + 7;
    int solve(int index, vector<int> &arr, int target, int n, vector<vector<int>> &dp){
    	if(index < 0){
    		if(target == 0)	return 1;
    		return 0;
    	}
    	if(dp[index][target] != -1){
    		return dp[index][target];
    	}
    
    	// notTake
    	int notTake = solve(index-1, arr, target, n, dp) % mod;
    	int take = 0;
    	if(arr[index] <= target){
    		take = solve(index-1, arr, target-arr[index], n, dp) % mod;
    	}
    
    	return dp[index][target] = (take + notTake)%mod;
    }
    int findWays(vector<int>& arr, int k){
    	int n = arr.size();
    	vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return solve(n-1, arr, k, n, dp);
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int total = 0;
        for(int num : arr){
            total += num;
        }
        
        if(total < diff  || (total - diff) % 2 != 0)    return 0;
        
        // we can convert this problem into the target sum problem
        int target = (total - diff)/2;
        return findWays(arr, target);
    }
};
