#include<iostream>
using namespace std;

// print divisors of a number
// https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1

class Solution {
  public:
    vector<int> getDivisors(int n) {
        vector<int> ans;
        for(int i = 1; i*i<=n; i++){
            if(n%i == 0){
                ans.push_back(i);
                if(n/i != i){
                    ans.push_back(n/i);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};