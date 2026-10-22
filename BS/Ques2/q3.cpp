#include<iostream>
using namespace std;

// nth root
// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

// we can optimize the given code while calculating the power of mid. mid^n is in 
// linear we can improve that to log(n) as well
class Solution {
  public:
    int nthRoot(int n, int m) {
        // nth root
        if(m == 1 || n == 1 || m == 0){
            return m;
        }
        
        int s = 0;
        int e = m/n;
        
        while(s < e){
            int mid = s + (e-s)/2;
            int power = 1;
            for(int i = 0; i<n; i++){
                power *= mid;
            }
            
            if(power == m){
                return mid;
            }
            else if(power > m){
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        
        return -1;
    }
};