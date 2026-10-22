#include<iostream>
using namespace std;

// Longest Repeating Character Replacement
// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(128, 0);
        int maxFreq = 0, maxLen = 0, l = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);
            // here you'll see if the char whose freq is max that is there to remove then we are not updating
            // the maxFreq, but it also works because the answer is gonna change only when we get a char with
            // maxFreq greater than the previous one, if we get the same maxFreq then we'll get the same answer
            // therefore it doesn't matter
            if ((r - l + 1) - maxFreq > k) {
                freq[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

