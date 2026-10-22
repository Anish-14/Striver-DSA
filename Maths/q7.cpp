#include<iostream>
using namespace std;

// Least Prime Factor
// https://www.geeksforgeeks.org/problems/least-prime-factor5216/1

class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans(n+1, 0);
        for(int i = 0; i<=n; i++){
            ans[i] = i;
        }
        
        for(int i = 2; i<=n; i++){
            if(ans[i] == i){
                for(long long j = 1LL*i*i; j<=n; j += i){
                    if(ans[j] == j){
                        ans[j] = i;
                    }
                }
            }
        }
        
        return ans;
    }
};