#include<iostream>
using namespace std;

// https://leetcode.com/problems/kth-missing-positive-number/description/
// Kth Missing Positive Number

// O(log(maxi)*log(n))
class Solution {
public:
    int getLower(vector<int> &arr, int n, int target){
        int s = 0, e = n-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(arr[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return e;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int maxi = arr[n-1];
        if(k > maxi - n){
            int ans = k+n;
            return ans;
        }

        int s = 1, e = maxi;
        while(s <= e){
            int mid = s + (e-s)/2;
            // cout<<"mid is "<<mid<<endl;
            
            int lower_bound = getLower(arr, n, mid);
            int missing_nums = mid-lower_bound-1;

            // cout<<"lower bound is --> "<<lower_bound<<endl;
            // cout<<"missing numbers "<<missing_nums<<endl;
            
            if(k >= missing_nums){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
            // cout<<"start and end after updation is "<<s<<" "<<e<<endl;
        }

        return e;
    }
};


// O(logn)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Number of missing positive integers before arr[mid]
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }

        // After the loop, the answer is left + k
        return left + k;
    }
};
