#include<iostream>
using namespace std;

// Good problem
// https://leetcode.com/problems/jump-game-ii/
// jump game 2

class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0, jump = 0, currEnd = 0;
        for(int i = 0; i<nums.size()-1; i++){
            // if(i > farthest)    return -1;
            farthest = max(farthest, i + nums[i]);

            if(i == currEnd){
                jump++;
                currEnd = farthest;
            }
        }

        return jump;
    }
};