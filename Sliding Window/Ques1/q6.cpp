#include<iostream>
using namespace std;

// Number of Substrings Containing All Three Characters
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> lastSeen(3, -1);
        int ans = 0;

        for(int i = 0; i<n; i++){
            lastSeen[s[i] - 'a'] = i;

            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                int minIndex = min({lastSeen[0], lastSeen[1], lastSeen[2]});
                ans += minIndex+1;
            }
        }

        return ans;
    }
};