#include<iostream>
using namespace std;

// Divide Two Integers
// https://leetcode.com/problems/divide-two-integers/description/

// Beautiful!
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        int sign = 1;
        if(dividend < 0 && divisor > 0) sign = 0;
        else if(dividend > 0 && divisor < 0) sign = 0;

        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);

        // we're just trying to break the quotient in power of 2
        int ans = 0;
        while(n >= d){
            int cnt = 0;
            // we are checking which multiple of 2^cnt is possible for given one
            // as we want to represent the quotient in these power of 2s
            while(n >= (d << (cnt+1))){
                cnt++;
            }

            ans += (1<<cnt);
            // as we've taken 2^cnt here so we are going to decrease n by d*2^k 
            // it is equivalent of taking the larget possible multiple of a power
            // of 2 for this loop. And we're going to represent the quotient in 
            // these power of 2s only
            n -= (d << cnt);
        }

        // 2^31 doesn't exist in 32 bit system
        if(ans == (1<<31) && sign){
            return INT_MAX;
        }

        if(ans == (1<<31) && !sign){
            return INT_MIN;
        }

        return sign ? ans : -ans;
    }
};