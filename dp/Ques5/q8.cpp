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
        if(isTrue)  return (exp[i] == 'T');
        else return (exp[i] == 'F');
    }
    if(dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }

    ll ways = 0;
    for(int k = i+1; k<=j-1; k+=2){      // k+=2 would be more efficient here as we want to go the signs for the partition
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




// Tabulation

int evaluateExp(string &exp) {
    int n = exp.length();
    // dp[i][j][isTrue] initialized to 0
    // dp[i][j][isTrue] stores the total number of valid parenthesizations for the
    //  sub-expression from index i to j that evaluate to isTrue (1 for True, 0 for False).
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    // 1. BASE CASES: i == j (Single Operands at even indices)
    for (int i = 0; i < n; i += 2) {
        dp[i][i][1] = (exp[i] == 'T') ? 1 : 0;
        dp[i][i][0] = (exp[i] == 'F') ? 1 : 0;
    }

    // 2. TABULATION LOOPS (Mirroring your memoization bounds)
    // Outer loop i: goes backwards from right to left
    for (int i = n - 1; i >= 0; i -= 2) {
        // Inner loop j: goes forwards from i+2 to n-1
        for (int j = i + 2; j < n; j += 2) {
            
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                ll ways = 0;

                // k loop: steps through operators between i and j
                for (int k = i + 1; k <= j - 1; k += 2) {
                    ll LT = dp[i][k - 1][1];
                    ll LF = dp[i][k - 1][0];
                    ll RT = dp[k + 1][j][1];
                    ll RF = dp[k + 1][j][0];

                    if (exp[k] == '&') {
                        if (isTrue) ways = (ways + (LT * RT) % mod) % mod;
                        else ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
                    }
                    else if (exp[k] == '|') {
                        if (isTrue) ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LT * RT) % mod) % mod;
                        else ways = (ways + (LF * RF) % mod) % mod;
                    }
                    else if (exp[k] == '^') {
                        if (isTrue) ways = (ways + (LF * RT) % mod + (LT * RF) % mod) % mod;
                        else ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
                    }
                }

                dp[i][j][isTrue] = ways;
            }
        }
    }

    // Your initial recursive call was solve(0, n-1, 1)
    return dp[0][n - 1][1];
}

