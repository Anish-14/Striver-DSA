#include<iostream>
using namespace std;

// Geek's training
// https://www.geeksforgeeks.org/problems/geeks-training/1

// Recursion
class Solution {
  public:
    int solve(vector<vector<int>> &arr, int day, int last){
        // base case
        if(day == 0){
            int maxi = 0;
            for(int i = 0; i<3; i++){
                if(i != last)
                    maxi = max(maxi, arr[0][i]);
            }
            
            return maxi;
        }
        
        int maxi = 0;
        for(int i = 0; i<3; i++){
            if(i != last){
                int temp = arr[day][i] + solve(arr, day-1, i);
                maxi = max(maxi, temp);
            }
        }    
    
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        return solve(arr, n-1, -1);
    }
};


// memo
class Solution {
  public:
    int solve(vector<vector<int>> &arr, int day, int last, vector<vector<int>> &dp){
        // base case
        if(day == 0){
            int maxi = 0;
            for(int i = 0; i<3; i++){
                if(i != last)
                    maxi = max(maxi, arr[0][i]);
            }
            
            return dp[day][last] = maxi;
        }
        
        if(dp[day][last] != -1) return dp[day][last];
        
        int maxi = 0;
        for(int i = 0; i<3; i++){
            if(i != last){
                int temp = arr[day][i] + solve(arr, day-1, i, dp);
                maxi = max(maxi, temp);
            }
        }    
    
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return solve(arr, n-1, 3, dp);
    }
};


// tabulation
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (4, 0));
        // we have to understand what the dp represents here
        // dp[i][j] represents that on the (i)th day if at the (i+1)th day j was selected then what should 
        // be our answer

        dp[0][0] = max(arr[0][1], arr[0][2]);       // at 0th day if at the 1st day we selected 0 then this should be the answer for this day
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

        for(int day = 1; day < n; day++){
           for(int last = 0; last<4; last++){
               for(int task = 0; task<3; task++){
                   if(task != last){
                       int point = arr[day][task] + dp[day-1][task];
                       dp[day][last] = max(dp[day][last], point);
                   }
               }
           }
        }
        
        return dp[n-1][3];
    }
};

// space optimization (made it constant space O(1))
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> prev(4, 0);
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));
        // return solve(arr, n-1, 3, dp);
        for(int day = 1; day < n; day++){
            vector<int> temp(4, 0);
           for(int last = 0; last<4; last++){
               for(int task = 0; task<3; task++){
                   if(task != last){
                       int point = arr[day][task] + prev[task];
                       temp[last] = max(temp[last], point);
                   }
               }
           }
           prev = temp;
        }
        
        return prev[3];
    }
};

