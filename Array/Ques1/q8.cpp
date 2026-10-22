#include<iostream> 
using namespace std;

// Sort 0,1,2
// https://leetcode.com/problems/sort-colors/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int zeroIndex = 0;
        int twoIndex = n-1;

        int i = 0;
        while(i < n && i <= twoIndex){
            if(nums[i] == 1){
                i++;
            }
            else if(nums[i] == 0){
                swap(nums[i], nums[zeroIndex]);
                zeroIndex++;
                i++;
            }
            else{      // 2
                swap(nums[i], nums[twoIndex]);
                twoIndex--;
            }
        }

        return;
    }
};

