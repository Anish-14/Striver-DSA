// Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/description/

#include<iostream>
using namespace std;

// recursion
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
        {
           return 1;
        }

        if(n == 2)
        {
           return 2;
        }

        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// memo
class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n <= 2){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};

// tabulation
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        vector<int> dp(n+1, -1);
        dp[1] = 1; dp[2] = 2;
        
        for(int i = 3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

// Space optimization
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        
        int first = 1; 
        int second = 2;
        int curr;
        
        for(int i = 3; i<=n; i++){
            curr = first + second;
            first = second;
            second = curr;
        }

        return second;
    }
};
