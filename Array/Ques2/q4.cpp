#include<iostream> 
using namespace std;

// Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num] = 1;
        }      

        // now we'll make our answer
        int ans = 0;
        
        for(auto &x : mp){
            int element = x.first;
            int sum = 1;
            int y = element;        // copy the element because we need to change it

            while(1){
                y++;
                if(mp.find(y) == mp.end()){
                    break;
                }
                else{
                    sum++;
                    mp.erase(y);
                }
            }
            y = element;
            while(1){
                y--;
                if(mp.find(y) == mp.end()){
                    break;
                }
                else{
                    sum++;
                    mp.erase(y);
                }
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};