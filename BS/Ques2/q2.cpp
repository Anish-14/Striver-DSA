#include<iostream>
using namespace std;

// Sqrt(x)
// https://leetcode.com/problems/sqrtx/description/

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1){
            return x;
        }

        int ans = -1;
        int s = 1;
        int e = x/2;

        while(s <= e){
            int mid = s + (e-s)/2;
            if(mid <= x/mid){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return ans;
    }
};

