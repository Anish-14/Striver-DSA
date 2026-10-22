#include<iostream>
using namespace std;

// Missing And Repeating
// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(2);
        for(int i = 0; i<n; i++){   // -1 because of 1 based indexing
            if(arr[abs(arr[i]) - 1] > 0){
                arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            }
            else{   // agar negative mila then this is our answer
                ans[0] = abs(arr[i]);
            }
        }
        
        // ab tak sabhi visited nodes per negative value hai
        // jo node visit nhi hua in 1 based indexing that is our missing
        // value
        
        for(int i = 0; i<n; i++){
            if(arr[i] > 0){
                ans[1] = i+1;
                break;
            }
        }
        
        return ans;
        
    }
};