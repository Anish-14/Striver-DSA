#include<iostream>
using namespace std;

// count inversions
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

class Solution {
  public:
    int merge(vector<int> &arr, int s, int mid, int e){
        int n1 = mid-s+1;
        int n2 = e-mid;
        
        vector<int> temp1(n1), temp2(n2);
        for(int i = 0; i<n1; i++){
            temp1[i] = arr[s+i];
        }
        for(int i = 0; i<n2; i++){
            temp2[i] = arr[mid+1+i];
        }
        
        int cnt = 0, i = 0, j = 0, start = s;
        while(i < n1 && j < n2){
            if(temp1[i] <= temp2[j]){
                arr[start] = temp1[i];
                i++;
                start++;
            }
            else{
                cnt += n1-i;
                arr[start] = temp2[j];
                j++;
                start++;
            }
        }
        while(i < n1){
            arr[start] = temp1[i];
            start++;
            i++;
        }
        while(j < n2){
            arr[start] = temp2[j];
            start++;
            j++;
        }
        
        return cnt;
    }
    int mergesort(vector<int> &arr, int s, int e){
        if(s >= e){
            return 0;
        }
        
        int mid = s + (e-s)/2;
        
        int left = mergesort(arr, s, mid);
        int right = mergesort(arr, mid+1, e);
        int middle = merge(arr, s, mid, e);
        
        return left+right+middle;
    }
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        
        return mergesort(arr, 0, n-1);
    }
};


