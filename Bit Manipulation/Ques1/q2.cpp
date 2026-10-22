#include<iostream>
using namespace std;

// Minimum Bit Flips to Convert Number
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/n

class Solution {
public:
    int cntSetBits(unsigned int num){
        int cnt = 0;
        while(num){
            cnt++;
            num = num&(num-1);
        }

        return cnt;
    }
    int minBitFlips(int start, int goal) {
        // we can take xor and then count set bits
        int temp = start^goal;
        return cntSetBits(temp);
    }
};

