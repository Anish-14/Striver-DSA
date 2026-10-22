#include<iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/implement-lower-bound/1
// Lower bound
// returns the index of the first element that is >= target (first element not less than target).
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size()-1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(arr[mid] >= target){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        
        return lo;
    }
};


