#include<iostream>
using namespace std;

// pow(x,n) where x and n are double numbers and n can be negative as well
// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0)  return 1;
        if(n == 1)  return x;

        if(n < 0){
            x = 1/x;
        }

        // this block is for int overflow as abs(n) can overflow n when n is INT_MIN
        if(n == INT_MIN){
            x = x*x;
            n = n/2;
        }
        n = abs(n);

        double ans = 1;
        while(n != 0){
            if(n&1){
                ans *= x;
                n--;
            }
            else{
                x = x*x;
                n = n/2;
            }
        }

        return ans;
    }
};

