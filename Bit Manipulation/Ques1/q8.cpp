#include<iostream>
using namespace std;

// XOR Operation in an Array
// https://leetcode.com/problems/xor-operation-in-an-array/description/

// Beautiful!!

class Solution {
public:
    int xorFromZero(int x){
        int rem = x%4;
        if(rem == 0)   return x;
        else if(rem == 1)    return 1; 
        else if(rem == 2)    return x+1;
        else    return 0;
    }

    int rangeXOR(int l, int r){
        return xorFromZero(l-1)^xorFromZero(r);
    }

    int xorOperation(int n, int start) {
        // dividing by 2 so that the sequence increases by 1 and not 2
        int s = start >> 1;

        // the range will be s -> s+n-1
        int temp = rangeXOR(s, s+n-1);  
        
        // now we've ignored the first bit because we divided it by 2
        // if it was 0 then it will always we 0, if it was 1 and n was odd then 
        // it will be 1 else 0
        int lastBit = (n&1) & (start&1);   // both needs to be odd for it to be one

        return ((temp << 1) | lastBit);
    }
};



