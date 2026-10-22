#include<iostream> 
using namespace std;

// Array Leaders
// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        // we'll be traversing it from the back
        // we can also solve it using stack
        ans.push_back(arr[n-1]);
        for(int i = n-2; i>=0; i--){
            if(arr[i] >= ans.back()){
                ans.push_back(arr[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};