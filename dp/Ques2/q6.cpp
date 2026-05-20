#include<iostream>
using namespace std;

// https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=PROBLEM
// count subsets with sum k 


// recursion + memo
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


// Tabulation   bottom up 
int mod = 1e9 + 7;
int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	// prepare the base cases
	dp[0][0] = 1;
	if(arr[0] <= k){
		dp[0][arr[0]] += 1;
	}

	for(int i = 1; i<n; i++){
		for(int tar = 0; tar <= k; tar++){
			int notTake = dp[i-1][tar] % mod;
			int take = 0;
			if(arr[i] <= tar){
				take = dp[i-1][tar-arr[i]] % mod;
			}

			dp[i][tar] = (take + notTake) % mod;
		}
	}

	return dp[n-1][k];
}



