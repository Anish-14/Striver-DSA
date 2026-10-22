#include<iostream> 
using namespace std;

// Majority Element --> Moore's Algorithm
// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // n/2 times
        // majority // rest elements

        // n/3 times --> tougher question than this 

        int ans = nums[0];
        int cnt = 1;

        for(int i = 1; i<nums.size(); i++){
            if(cnt == 0){
                ans = nums[i];
                cnt = 1;
                continue;
            }

            if(nums[i] == ans){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        return ans;
    }
};


// Majority element 2
// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int maj1 = 0;
        int maj2 = 0;

        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] == maj1){
                cnt1++;
            }
            else if(nums[i] == maj2){
                cnt2++;
            }
            else if(cnt1 == 0){
                maj1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                maj2 = nums[i];
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        // candidates --> maj1, maj2 
        cnt1 = 0;
        cnt2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == maj1){
                cnt1++;
            }
            else if(nums[i] == maj2){
                cnt2++;
            }
        }

        vector<int> ans;
        if(cnt1 > n/3){
            ans.push_back(maj1);
        }
        if(cnt2 > n/3){
            ans.push_back(maj2);
        }

        return ans;
    }
};