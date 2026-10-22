#include<iostream> 
using namespace std;

// Rotate Array by k places
// https://leetcode.com/problems/rotate-array/description/

class Solution {
public:
    void reverse(vector<int> &arr, int s, int e){
        while(s < e){
            swap(arr[s++],arr[e--]);
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        if(k == 0){
            return;
        }
	
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};
