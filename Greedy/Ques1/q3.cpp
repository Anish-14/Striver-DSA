#include<iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-job-first/1
// shortest job first

class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        int n = bt.size();
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans += bt[i] * (n-i-1);
        }
        
        return ans/n;
    }
};
