#include<iostream> 
using namespace std;

// Longest Subarray with Sum K
// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // sliding window
        // I can not demolish any window because there might be a 
        // negative number ahead
        // cumulative sum with index? 
        // 
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
            // cout<<sum<<endl;
            
            // save the cumulative sum 
            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
            
            int toFind = sum - k;
            if(mp.find(toFind) != mp.end()){
                // cout<<"PAPAPAPAPAPA"<<endl;
                int index = mp[toFind];
                ans = max(ans, i - index);
            }
        }
        
        return ans;
    }
};


// This will work only if there are only non negative numbers
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int left = 0, right = 0;
        long long sum = arr[0];
        int maxLen = 0;
        int n = arr.size();
        
        while(right < n){
            while(left <= right && sum > k){
                sum -= arr[left];
                left++;
            }
            
            if(sum == k){
                maxLen = max(maxLen, right-left+1);
            }
            
            right++;
            if(right < n)   sum += arr[right];
        }
        
        return maxLen;
    }
};