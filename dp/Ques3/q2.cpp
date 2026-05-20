#include<iostream>
using namespace std;

// Min cost to cut a stick
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/


// Recursion 
class Solution {
public:
    int solve(int i, int j, vector<int> &cuts){
        if(i > j){
            return 0;
        }
        int mini = INT_MAX;
        for(int index = i; index <= j; index++){
            int cut = cuts[j+1] - cuts[i-1] + solve(i, index-1, cuts) + solve(index+1, j, cuts);
            mini = min(mini, cut);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        return solve(1, cuts.size() - 2, cuts);
    }
};


// Memoization 
class Solution {
public:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int index = i; index <= j; index++){
            int cut = cuts[j+1] - cuts[i-1] + solve(i, index-1, cuts, dp) + solve(index+1, j, cuts, dp);
            mini = min(mini, cut);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(1, m-2, cuts, dp);
    }
};

// Tabulation 
// just go in reverse direction, 'i' was going from 1 -> m-2 and 'j' from m-2 -> 1 so in tabulation 
// just do the reverse as we are going bottom up
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for(int i = m-2; i>=1; i--){
            for(int j = i; j<=m-2; j++){
                int mini = INT_MAX;
                for(int index = i; index <= j; index++){
                    int cut = cuts[j+1] - cuts[i-1] + dp[i][index-1] + dp[index+1][j];
                    mini = min(mini, cut);
                }
                dp[i][j] = mini;
            }
        }

        return dp[1][m-2];
    }
};


