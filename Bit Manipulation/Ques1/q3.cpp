#include<iostream>
using namespace std;

// All Subsequences of a String
// https://www.geeksforgeeks.org/problems/power-set4302/1

class Solution {
  public:
    vector<string> powerSet(string &s) {
        int n = s.size();
        int subsets = (1<<n);
        vector<string> ans;
        
        // here num's bits represent which index to take from the string so it works
        for(int num = 0; num < subsets; num++){
            string temp = "";
            for(int i = n-1; i>=0; i--){
                if(num & (1<<i)){
                    temp.push_back(s[n-1-i]);
                }
            }
            ans.push_back(temp);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

