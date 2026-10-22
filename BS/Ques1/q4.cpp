#include<iostream>
using namespace std;

// Floor in a sorted array
// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        // code here
        int lo = 0, hi = arr.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(arr[mid] <= x){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        
        return hi;
    }
};



