#include<iostream>
using namespace std;

// all prime factor of a number
// https://www.geeksforgeeks.org/problems/prime-factor-of-a-number/1

class Solution {
  public:
    vector<int> primeFactors(int n) {
        if(n == 1)  return {};
        int temp = n;
        vector<int> ans;
        
        for(int i = 2; i*i<=n; i++){
            if(temp == 1)  break;
            while(temp%i == 0){
                ans.push_back(i);
                temp = temp/i;
            }
        }
        
        if(temp != 1){
            ans.push_back(temp);
        }
        return ans;
    }
};


