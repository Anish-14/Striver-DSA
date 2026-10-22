#include<iostream>
using namespace std;

// Palindrome Partitioning 
// https://leetcode.com/problems/palindrome-partitioning/description/


class Solution {
public:
    bool isPal(string &s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }

        return true;
    }
    void solve(string &s, vector<vector<string>> &ans, vector<string> temp, int index, int n){
        // base case
        if(index == n){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i<n; i++){
            if(isPal(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                solve(s, ans, temp, i+1, n);
                temp.pop_back();
            }
        }

        return;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, ans, temp, 0, n);

        return ans;
    }
};



