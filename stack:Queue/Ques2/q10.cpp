#include<iostream>
#include<vector>
using namespace std;

// Smallest Subsequence of Distinct Characters
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        unordered_map<char, int> lastOccurance;
        for(int i = 0; i<n; i++){
            lastOccurance[s[i]] = i;
        }

        stack<char> st;
        vector<bool> visited(26);

        for(int i = 0; i<n; i++){
            if(visited[s[i] - 'a']){
                continue;
            }

            while(!st.empty() && s[i] < st.top() && i < lastOccurance[st.top()]){
                visited[st.top() - 'a'] = 0;
                st.pop();
            }

            visited[s[i] - 'a'] = 1;
            st.push(s[i]);
        }

        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};