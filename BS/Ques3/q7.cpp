#include<iostream>
using namespace std;

// kth element of two sorted array
// https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n = a.size(), m = b.size();
        if(n > m){
            kthElement(b ,a, k);
        }
        
        // a is smaller array
        int low = 0, high = min(n,k);
        // cout<<high<<endl;
        while(low <= high){
            int mid1 = low + (high-low)/2;
            int mid2 = k-mid1;
            
            if(mid2 > m){
                low = mid1+1;
                continue;
            }
            
            int left1 = (mid1 == 0 ? INT_MIN : a[mid1-1]);
            int right1 = (mid1 == n ? INT_MAX : a[mid1]);
            
            int left2 = (mid2 == 0 ? INT_MIN : b[mid2-1]);
            int right2 = (mid2 == m ? INT_MAX : b[mid2]);
            
            // valid partition
            if(left1 <= right2 && left2 <= right1){
                // got our answer
                // cout<<low<<" "<<high<<endl;
                return max(left1, left2);
            }
            else if(left1 > right2){
                high = mid1-1;
            }
            else{
                low = mid1+1;
            }
        }
            
        return -1;
    }
};



