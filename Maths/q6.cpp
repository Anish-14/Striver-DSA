#include<iostream>
using namespace std;

// Primes in range
// https://www.geeksforgeeks.org/problems/find-prime-numbers-in-a-range4718/1

class Solution {
  public:
    vector<int> primeRange(int l, int r) {
        vector<int> ans;
        vector<int> primes(r+1,1);
        
        for(int i = 2; i<=r; i++){
            if(primes[i] == 1){
                for(long long j = 1LL*i*i; j<=r; j += i){
                    primes[j] = 0;
                }
            }
        }
        
        for(int i = max(2,l); i<=r; i++){
            if(primes[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
