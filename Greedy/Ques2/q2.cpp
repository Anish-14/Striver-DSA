#include<iostream>
using namespace std;

// Valid Parenthesis String
// https://leetcode.com/problems/valid-parenthesis-string/description/

// Very Good Problem
// We just tried the all the possiblities of the recursive solution in these two variables
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int min = 0, max = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                min++;
                max++;
            }
            else if(s[i] == ')'){
                min--;
                max--;
            }
            else{
                min = min-1;
                max = max+1;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }   

        return (min == 0);
    }
};




// We can try a recursive approach where we can try all possiblity and we can further 
// optimise it using DP to O(n^2)

// f(s,ind,cnt){
//     if(cnt < 0) return false;
//     if(ind == n){
//         return cnt == 0;
//     }

//     if(s[ind] == '('){
//         return f(s,ind+1,cnt+1);
//     }
//     if(s[ind] == ')'){
//         return f(s,ind+1,cnt-1);
//     }

//     return f(s,ind+1,cnt) || f(s,ind+1,cnt+1) || f(s,ind+1,cnt-1);
// }

// recur + memo
class Solution {
public:
    bool solve(string &s, int ind, int cnt, int n, vector<vector<int>> &dp) {
        if (cnt < 0) return false;
        if (ind == n) return cnt == 0;
        if (dp[ind][cnt] != -1) return dp[ind][cnt];

        if (s[ind] == '(') {
            return dp[ind][cnt] = solve(s, ind + 1, cnt + 1, n, dp);
        }
        if (s[ind] == ')') {
            return dp[ind][cnt] = solve(s, ind + 1, cnt - 1, n, dp);
        }

        // '*' case: try empty string, '(', and ')'
        bool empty = solve(s, ind + 1, cnt, n, dp);
        bool open  = solve(s, ind + 1, cnt + 1, n, dp);
        bool close = solve(s, ind + 1, cnt - 1, n, dp);

        return dp[ind][cnt] = (empty || open || close);
    }

    bool checkValidString(string s) {
        int n = s.length();
        // cnt can at most be n
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(s, 0, 0, n, dp);
    }
};


// Tabulation 
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        // dp[ind][cnt]
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        // Base case: ind == n
        dp[n][0] = true;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cnt = 0; cnt <= n; cnt++) {
                bool ans = false;

                if (s[ind] == '(') {
                    if (cnt + 1 <= n) ans = dp[ind + 1][cnt + 1];
                }
                else if (s[ind] == ')') {
                    if (cnt - 1 >= 0) ans = dp[ind + 1][cnt - 1];
                }
                else {
                    // '*' case
                    bool empty = dp[ind + 1][cnt];
                    bool open  = (cnt + 1 <= n) ? dp[ind + 1][cnt + 1] : false;
                    bool close = (cnt - 1 >= 0) ? dp[ind + 1][cnt - 1] : false;
                    ans = (empty || open || close);
                }

                dp[ind][cnt] = ans;
            }
        }

        return dp[0][0];
    }
};
