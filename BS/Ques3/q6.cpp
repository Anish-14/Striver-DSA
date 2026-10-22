#include<iostream>
using namespace std;

// Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/


// This question teaches us how to make partitions such that the whole left half is on one side and 
// the other is on the other(right) side this way we can find the median in really easy manner

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(n > m){
            return findMedianSortedArrays(b, a);
        }
        
        int lo = 0, hi = n;
        while(lo <= hi){
            int mid1 = lo + (hi - lo)/2;
            int mid2 = (n+m+1)/2 - mid1;
            
            int l1 = (mid1 == 0 ? INT_MIN : a[mid1-1]);
            int r1 = (mid1 == n ? INT_MAX : a[mid1]);
            
            int l2 = (mid2 == 0 ? INT_MIN : b[mid2-1]);
            int r2 = (mid2 == m ? INT_MAX : b[mid2]);
            
            // if it is a valid partition
            if(l1 <= r2 && l2 <= r1){
                if((n+m)%2 == 0){
                    return (max(l1, l2) + min(r1, r2))/2.0;
                }
                else{
                    return max(l1, l2);
                }
            }
            else if(l1 > r2){
                hi = mid1-1;
            }
            else{
                lo = mid1+1;
            }
        }
        
        return 0.0;
    }
};