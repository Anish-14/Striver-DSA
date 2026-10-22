#include<iostream>
using namespace std;

// Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

class Solution {
public:
    int getDay(vector<int> &weights, int n, int mid){
        int cnt = 0, sum = 0;
        for(int i = 0; i<n; i++){
            if(weights[i] > mid){
                return INT_MAX;
            }

            if(sum + weights[i] <= mid){
                sum += weights[i];
            }
            else{
                cnt++;
                sum = weights[i];
            }
        }

        return cnt+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += weights[i];
        }

        int s = 1, e = sum;
        while(s <= e){
            int mid = s + (e-s)/2;

            int currDays = getDay(weights, n, mid);

            if(currDays <= days){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        return s;
    }
};

