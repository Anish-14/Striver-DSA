#include<iostream>
using namespace std;

// reverse pairs
// https://leetcode.com/problems/reverse-pairs/

class Solution {
public:

    int merge(vector<int> &nums, int low, int mid, int high){ 
        vector<int> temp;
        int st = low;
        int st2 = mid+1;
        int ans = 0;

        // traverse
        while(st <= mid && st2 <= high){
            if((long long)nums[st] > (long long)2*nums[st2]){
                ans += mid - st + 1;
                st2++;
            }
            else{
                st++;
            }
        }
        
        // merge the arrays
        st = low;
        st2 = mid+1;
        while(st <= mid && st2 <= high){
            if(nums[st] > nums[st2]){
                temp.push_back(nums[st2]);
                st2++;
            }
            else{
                temp.push_back(nums[st]);
                st++;
            }
        }
        while(st <= mid){
            temp.push_back(nums[st]);
            st++;
        }
        while(st2 <= high){
            temp.push_back(nums[st2]);
            st2++;
        }

        for(int i = low; i<=high; i++){
            nums[i] = temp[i-low];
        }

        // return my answer
        return ans;
    }
    int mergeSort(vector<int> &nums, int low, int high){
        // base case
        if(low >= high){
            return 0;
        }

        int ans = 0;
        int mid = low + (high - low)/2;

        ans += mergeSort(nums, low, mid);
        ans += mergeSort(nums, mid+1, high);
        ans += merge(nums, low, mid, high);

        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};
