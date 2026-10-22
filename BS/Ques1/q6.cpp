#include<iostream>
using namespace std;

// Search in Rotated Sorted Array
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// pivot method
class Solution {
public:
    int getPivot(vector<int> &nums, int s, int e){
        while(s < e){
            if(nums[e] > nums[s]){
                return s;
            }

            int mid = s + (e-s)/2;
            if(nums[mid] < nums[s]){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }

        return s;
    }

    int binarySearch(vector<int> &nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        // we need to find the pivot in log(n) and then the target also in log(n)
        int n = nums.size();
        int pivot = getPivot(nums, 0, n-1);

        // cout<<pivot<<endl;
        // now I want to do the binary search
        if(target >= nums[pivot] && target <= nums[n-1]){
            return binarySearch(nums, pivot, n-1, target);
        }
        else{
            return binarySearch(nums, 0, pivot-1, target);
        }

    }
};


// direct method
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[lo] <= arr[mid]){ // left half is sorted
                if(arr[lo] <= target && target <= arr[mid]){   // if it is between them
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{           // right half is sorted
                if(arr[mid] <= target && target <= arr[hi]){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }

        return -1;
    }
};

