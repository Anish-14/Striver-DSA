#include<iostream>
using namespace std;

// Palindromic Partitioning
// https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1


// recursion + memo
class Solution {
  public:   
    bool isPal(string &s, int i, int j){
        while(i<j){
            if(s[i++] != s[j--])    return false;
        }
        return true;
    }
    int solve(int i, int n, string &s, vector<int> &dp){
        // base cases
        if(i == n)  return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        int mini = INT_MAX;
        // let's partition 
        for(int j = i; j<n; j++){
            if(isPal(s, i, j)){
                int cost = 1 + solve(j+1, n, s, dp);    
                mini = min(mini, cost);
            }
        }
        
        return dp[i] = mini;
    }
    int palPartition(string &s) {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, n, s, dp) - 1;      // we returned with a "-1" because it is doing partition like this --> A|B|C| so the last one shouldn't count 
    }
};


// Tabulation 
class Solution {
  public:   
    bool isPal(string &s, int i, int j){
        while(i<j){
            if(s[i++] != s[j--])    return false;
        }
        return true;
    }
    int palPartition(string &s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        
        for(int i = n-1; i>=0; i--){
            int mini = INT_MAX;
        
            for(int j = i; j<n; j++){
                if(isPal(s, i, j)){
                    int cost = 1 + dp[j+1];
                    mini = min(mini, cost);
                }
            }
            
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};