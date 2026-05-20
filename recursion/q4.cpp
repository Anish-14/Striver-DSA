// subset Sums
// https://www.geeksforgeeks.org/problems/subset-sums2234/1

#include<iostream>
using namespace std;
class Solution {
  public:
    void printSums(vector<int> &arr, int sum, int index, vector<int> &ans){
        if(index >= arr.size()){
            ans.push_back(sum);
            return;
        }
        
        // not Take
        printSums(arr, sum, index+1, ans);
        // take
        printSums(arr, sum + arr[index], index+1, ans);
        
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        printSums(arr, 0, 0, ans);
        
        return ans;
    }
};