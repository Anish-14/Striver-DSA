#include<iostream>
using namespace std;


// Boolean Evaluation
// https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=PROBLEM

// recursion + memoization 
#define ll long long
int mod = 1e9 + 7;
long long solve(int i, int j, bool isTrue, string &exp, vector<vector<vector<int>>> &dp){
    // base cases
    if(i > j)   return 0;
    if(i == j){
        if(isTrue)  return exp[i] == 'T';
        else return exp[i] == 'F';
    }
    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    ll ways = 0;
    for(int k = i+1; k<=j-1; k++){
        // let's put a partition here
        ll LT = solve(i, k-1, 1, exp, dp);
        ll LF = solve(i, k-1, 0, exp, dp);
        ll RT = solve(k+1, j, 1, exp, dp);
        ll RF = solve(k+1, j, 0, exp, dp);

        if(exp[k] == '&'){
            if(isTrue)  ways = (ways + (LT*RT)%mod )%mod;
            else ways = (ways + (LT*RF)%mod + (LF*RT)%mod + (LF*RF)%mod )%mod;
        }
        else if(exp[k] == '|'){
            if(isTrue){
                ways = (ways + (LT*RF)%mod + (LF*RT)%mod + (LT*RT)%mod )%mod;
            }
            else {
                ways = (ways + (LF * RF)%mod )%mod;
            }
        }
        else{
            // XOR
            if(isTrue){
                ways = (ways + (LF*RT)%mod + (LT*RF)%mod )%mod;
            }
            else{
                ways = (ways + (LT*RT)%mod + (LF*RF)%mod )%mod;
            }
        }

    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
    int n = exp.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int>(2, -1)));
    return solve(0, n-1, 1, exp, dp);
}





