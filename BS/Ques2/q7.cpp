#include<iostream>
using namespace std;

// K-th Smallest Prime Fraction
// https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0, right = 1;
        vector<int> res;

        while(left <= right){
            double mid = left + (right-mid)/2.0;
            int j = 1, total = 0, num = 0, den = 0;
            double frac = 0;
            for(int i = 0; i<n; i++){
                while(j<n && arr[i] >= arr[j]*mid){
                    j++;
                }

                // these are the cnt of fractions which are less than mid
                total += n-j;    

                if(j<n && frac < (arr[i]*1.0)/arr[j]){
                    frac = (arr[i]*1.0)/arr[j];
                    num = i;
                    den = j;
                }
            }

            if(total == k){
                res = {arr[num], arr[den]};
                break;
            }
            else if(total < k){
                left = mid;
            }
            else{
                right = mid; 
            }
        }

        return res;
    }
};

