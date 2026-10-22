#include<iostream>
using namespace std;

// Sieve of Eratosthenes
// https://www.geeksforgeeks.org/problems/sieve-of-eratosthenes5242/1

class Solution {
  public:
    vector<int> sieve(int n) {
        vector<int> ans;
        vector<int> prime(n+1, 1);
        
        for(int i = 2; i<=n; i++){
            if(prime[i]){
                ans.push_back(i);
                for(int j = 1LL*i*i; j<=n; j += i){
                    prime[j] = 0;
                }
            }
        }
        
        return ans;
    }
};
