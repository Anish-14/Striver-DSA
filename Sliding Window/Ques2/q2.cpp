#include<iostream>
using namespace std;

// Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/description/

// Awesome problem
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()){
            return "";
        }

        unordered_map<char,int> m;
        for(int i = 0; i<t.length(); i++){
            m[t[i]]++;
        }

        int startIndex = 0;
        vector<int> diff = {0, INT_MAX};
        int remainingChar = t.length();

        for(int endIndex = 0; endIndex < s.length(); endIndex++){
            char ch = s[endIndex];
            if(m.find(ch) != m.end() && m[ch] > 0){
                remainingChar--;
            }
            m[ch]--;

            if(remainingChar == 0){
                // ignore the initial characters which are not in t
                while(true){
                    char start = s[startIndex];
                    if(m.find(start) != m.end() && m[start] == 0){
                        break;
                    }
                    m[start]++;
                    startIndex++;
                }

                // ans save 
                if(endIndex - startIndex < diff[1] - diff[0]){
                    diff[0] = startIndex;
                    diff[1] = endIndex;
                }

                // move forward
                m[s[startIndex]]++;
                startIndex++;
                remainingChar++;
            }
        }

        if(diff[1] >= s.length()){
            return "";
        }

        return s.substr(diff[0], diff[1] - diff[0] + 1);
    }
};