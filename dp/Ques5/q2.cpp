#include<iostream>
using namespace std;

// Largest Divisible Subset
// https://leetcode.com/problems/largest-divisible-subset/description/


// variation of LIS only
// we just sorted our input array and we changed the if logic as given in the question 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);      // represent the length of max subarray/subsequenc && the hash records the chain to our answer
        sort(nums.begin(), nums.end());

        int maxi = 1;
        int maxIndex = 0;

        for(int i = 0; i<n; i++){
            hash[i] = i;    // mark each cell to itself first
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                    dp[i] = 1 + dp[j];  // update the length
                    hash[i] = j;        // note its tail
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];       // save the best result here
                maxIndex = i;       // save its index too
            }
        }

        // generating our answer now
        vector<int> ans;
        ans.push_back(nums[maxIndex]);

        while(hash[maxIndex] != maxIndex){
            maxIndex = hash[maxIndex];
            ans.push_back(nums[maxIndex]);   
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

