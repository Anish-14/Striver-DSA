#include<iostream>
using namespace std;

// Rod cutting problem
// https://www.naukri.com/code360/problems/rod-cutting-problem_800284?leftPanelTabValue=PROBLEM

// Recursion 
int solve(int index, int remainingSize, vector<int> &price){
	if(index == 1){
		int val = remainingSize*price[index-1];
		return val;
	}

	// notTake
	int notTake = solve(index-1, remainingSize, price);
	int take = 0;
	if(index <= remainingSize){
		take = price[index-1] + solve(index, remainingSize-index, price);
	}

	return max(notTake, take);
}
int cutRod(vector<int> &price, int n){
	return solve(n, n, price);
}

// Memo
int solve(int index, int remainingSize, vector<int> &price, vector<vector<int>> &dp){
	if(index == 1){
		int val = remainingSize*price[index-1];
		return val;
	}
	if(dp[index][remainingSize] != -1){
		return dp[index][remainingSize];
	}

	// notTake
	int notTake = solve(index-1, remainingSize, price, dp);
	int take = 0;
	if(index <= remainingSize){
		take = price[index-1] + solve(index, remainingSize-index, price, dp);
	}

	return dp[index][remainingSize] = max(notTake, take);
}
int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	return solve(n, n, price, dp);
}


// Tabulation 
int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	// base case
	for(int i = 0; i<=n; i++){
		dp[1][i] = price[0]*i;
	}

	for(int index = 2; index <= n; index++){
		for(int remainingSize = 0; remainingSize <= n; remainingSize++){
			int notTake = dp[index-1][remainingSize];
			int take = 0;
			if(index <= remainingSize){
				take = price[index-1] + dp[index][remainingSize-index];
			}

			dp[index][remainingSize] = max(notTake, take);
		}
	}

	return dp[n][n];
}




