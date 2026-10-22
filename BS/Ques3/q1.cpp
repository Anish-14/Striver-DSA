#include<iostream>
using namespace std;

// Aggressive cows
// https://www.geeksforgeeks.org/problems/aggressive-cows/1

class Solution {
  public:
    bool isPossible(vector<int> &arr, int mid, int cows){
        int cntCows = 1, last = arr[0];
        int n = arr.size();
        for(int i = 1; i<n; i++){
            if(arr[i] - last >= mid){
                cntCows++;
                last = arr[i];
            }
            
            if(cntCows >= cows) return true;
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int low = 1, high = arr[n-1]-arr[0];
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(isPossible(arr, mid, k)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return high;
    }
};

