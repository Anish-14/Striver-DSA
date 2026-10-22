#include<iostream> 
using namespace std;

// Rearrange Array Elements by Sign
// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

// Approach 1 : 
// Make a pos element array and a neg element array and then copy one by one in the main array 


// Approach 2:
// Create a seperate array and fix evenIdx --> pos && negIds --> neg element so by doing this 
// we can do as well


// I am implementing the approach 2 here
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0, neg = 1;
        vector<int> ans(n);

        for(int i = 0; i<n; i++){
            if(nums[i] > 0){
                ans[pos] = nums[i];
                pos += 2;
            }
            else{
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};
