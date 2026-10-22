#include<iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// Minimum Platforms

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int ans = 0;
        int cnt = 0;
        
        int i = 0, j = 0;
        
        while(i < n && j < n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;  
            }
            else{
                cnt--;
                j++;
            }
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};