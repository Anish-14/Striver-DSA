#include<iostream>
using namespace std;

//  https://leetcode.com/problems/jump-game/
//  jump game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = nums[0];
        for(int i = 0; i<nums.size(); i++){
            if(i > maxReach){
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};

