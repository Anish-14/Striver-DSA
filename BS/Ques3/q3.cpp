#include<iostream>
using namespace std;

// Painter's problem
// https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

class Solution {
  public:
    bool isPossible(vector<int> &arr, long long mid, int k){
        int cnt = 1, n = arr.size();
        long long sum = 0;
        
        for(int i = 0; i<n; i++){
            if(sum + arr[i] <= mid){
                sum += arr[i];
            }
            else{
                cnt++;
                sum = arr[i];
            }
            
            if(cnt > k) return true;
        }
        
        return false;
    }
    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0);
        
        while(low <= high){
            long long mid = low + (high-low)/2;
            
            if(isPossible(arr, mid, k)){
                // isPossible means that do we need more than k students so we need to 
                // increase the number of pages
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return low;
    }
};
