#include<iostream>
using namespace std;

// Single Number III
// https://leetcode.com/problems/single-number-iii/description/

// WOW!!
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorall = 0;
        for(int i = 0; i<nums.size(); i++){
            xorall = xorall^nums[i];
        }

        // this will give us a number with only rightmost bit of xorall
        // -x = ~x + 1
        // due to negation all the bits left of it are inverted and the rightmost bit beccomes 1 again 
        // because of the 1 carry that we do afterwards. hence it gives a number with only a bit at the
        // rightmost position
        int rightmost = xorall & -xorall;
        int b1 = 0, b2 = 0;

        // xor being 1 at rightmost position represents that b1 && b2 has different bits at that position.
        // We group the array into two groups one containing a set bit at rightmost position and 
        // the other who don't and create our number
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] & rightmost) b1 = b1^nums[i];
            else b2 = b2^nums[i];
        }

        return {b1, b2};
    }
};