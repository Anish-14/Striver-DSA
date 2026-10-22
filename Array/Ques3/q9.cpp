#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1#expected-approach-using-pattern-matching-on-time-and-on-space

class Solution {
  public:
    vector<int> computeLPS(string &pattern){
        int n = pattern.size();
        
        vector<int> lps(n, 0);
        lps[0] = 0;
        
        int len = 0, i = 1;
        
        while(i < n){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    len = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    bool areRotations(string &s1, string &s2) {
        if(s1.size() != s2.size())  return false;
        
        string text = s1 + s1;
        string pattern = s2;
        
        int n = text.size();
        int m = pattern.size();
        
        vector<int> lps = computeLPS(pattern);
        
        int i = 0, j = 0;
        while(i < n){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }
            
            // pattern found
            if(j == m){
               return true; 
            }  
            else if(i < n && text[i] != pattern[j]){    // mismatch found
                if(j != 0){
                    j = lps[j-1];    
                }   
                else{
                    i++;
                }
            }
        }
        
        return false;
    }
};