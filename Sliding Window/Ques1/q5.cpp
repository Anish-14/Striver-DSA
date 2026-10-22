#include<iostream>
using namespace std;

// Longest Substring With At Most K Distinct Characters 
// https://www.naukri.com/code360/problems/distinct-characters_2221410

class Solution {
public:
    int kDistinctChars(int k, string &str) {
        int n = str.size();
        if (k == 0 || n == 0) return 0;

        unordered_map<char, int> freq;
        int l = 0, maxLen = 0;

        for (int r = 0; r < n; r++) {
            freq[str[r]]++;

            // Shrink window from the left if distinct character count exceeds k
            while(freq.size() > k) {
                freq[str[l]]--;
                if(freq[str[l]] == 0){
                    freq.erase(str[l]);
                }
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};