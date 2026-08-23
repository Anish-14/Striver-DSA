#include<iostream>
#include<vector>
using namespace std;

// The Celebrity Problem
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i<n; i++){
            mat[i][i] = 0;
        }
            
        int top = 0, bottom = n-1;
        
        while(top < bottom){
            // if top knows bottom then it can't be celebrity
            if(mat[top][bottom] == 1){
                top++;
            }
            else if(mat[bottom][top] == 1){
                bottom--;
            }
            else{
                // if both doesn't know each other then they can't be
                // a celebrity because celebrity is known by all
                top++;
                bottom--;
            }
        }
        
        // now we have our candidate ready
        // row check
        for(int i = 0; i<n; i++){
            if(mat[top][i] == 1){
                return -1;
            }
        }
        
        // col check
        for(int i = 0; i<n; i++){
            if(i != top && mat[i][top] == 0){
                return -1;
            }
        }
        
        return top;
    }
};

