#include<iostream>
#include<vector>
using namespace std;

// Remove K Digits
// https://leetcode.com/problems/remove-k-digits/description/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string s = "";

        for(int i = 0; i<n; i++){
            if(s.empty()){
                s.push_back(num[i]);
            }
            else{
                while(k > 0 && !s.empty() && (int)(s.back() - '0') > (int)(num[i] - '0')){
                    s.pop_back();
                    k--;
                }

                s.push_back(num[i]);
            }
        }

        while(k--){
            if(s.empty())   break;
            s.pop_back();
        }

        string ans = "";
        int size = s.size();

        int i = 0;
        // skip leading zeros
        while(i < size){
            if(s[i] == '0'){
                i++;
            }
            else{
                break;
            }
        }

        // save the answer
        while(i < size){
            // cout<<"I was here "<<endl;
            ans.push_back(s[i]);
            i++;
        }

        if(ans.size() == 0){
            return "0";
        }
        return ans;
    }
};







