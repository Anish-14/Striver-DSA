#include<iostream>
using namespace std;

// Row with Max 1s in Rowwise Sorted
// http://geeksforgeeks.org/problems/row-with-max-1s0023/1

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int idx = -1, size = 0;
        int n = arr.size(), m = arr[0].size();
        
        for(int i = 0; i<n; i++){
            int one = upper_bound(arr[i].begin(), arr[i].end(), 0) - arr[i].begin();    
            
            if(m-one > size){
                size = m-one;
                idx = i;
            }
        }
        
        return idx;
    }
};
