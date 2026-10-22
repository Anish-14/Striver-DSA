#include<iostream>
using namespace std;

// Count Subarrays with given XOR
// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;  // xor, cnt;
        mp[0] = 1;
        
        int temp = 0, ans = 0;
        for(int i = 0; i<n; i++){
            temp = temp^arr[i];
            
            int target = temp^k;
            if(mp.find(target) != mp.end()){
                ans += mp[target];
            }
            
            mp[temp]++;
        }
        
        return ans;
    }
};



