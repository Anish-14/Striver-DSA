#include<iostream>
using namespace std;

// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution{
public:
    void remove(unordered_map<char,int> &mp, int start, int end, string &s){
        for(int i = start; i<=end; i++){
            mp.erase(s[i]);
        }
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;          // char, index 

        int st = 0;
        int e = 0;
        int ans = 0;

        for(int i = 0; i<n; i++){
            // if it exist
            if(mp.find(s[i]) != mp.end()){
                if(e-st > ans){
                    ans = e-st;
                }
                // remove from map
                int index = mp[s[i]];
                remove(mp, st, index, s);

                st = index+1;
            }
            
            e++;
            mp[s[i]] = i;
        }

        if(e-st > ans){
            ans = e-st;
        }

        return ans;
    }
};


// Optimized solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp; // char -> last seen index
        int st = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // If character was seen and is within the current window
            if (mp.count(s[i]) && mp[s[i]] >= st) {
                st = mp[s[i]] + 1;
            }
            
            mp[s[i]] = i;
            ans = max(ans, i - st + 1);
        }

        return ans;
    }
};
