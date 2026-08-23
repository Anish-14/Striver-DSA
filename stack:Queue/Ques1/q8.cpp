#include<iostream>
#include<vector>
using namespace std;

// Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water/description/


// TC O(n) && SC O(n) 
class Solution {
public:
    int trap(vector<int>& height) {
        // leftHeight & rightHeight
        int n = height.size();

        // build the leftHeight
        vector<int> leftHeight(n);
        leftHeight[0] = height[0];
        for(int i = 1; i<n; i++){
            leftHeight[i] = max(leftHeight[i-1], height[i]);
        }

        // build the rightHeight
        vector<int> rightHeight(n);
        rightHeight[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            rightHeight[i] = max(rightHeight[i+1], height[i]);
        }

        int ans = 0;
        for(int i = 0; i<n; i++){
            ans += min(leftHeight[i], rightHeight[i]) - height[i];
        }

        return ans;
    }
};


// best one 
// TC O(n) && SC O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int leftMax = 0, rightMax = 0, total = 0;

        while(l < r){
            // we're always gonna process the smaller one so that we are protected from atleast
            // one end and we've to just think about the other end
            if(height[l] <= height[r]){
                if(leftMax > height[l]){
                    // we can save water here 
                    total += leftMax - height[l];
                }
                else{
                    // we've got a new leftMax for the other numbers to come
                    leftMax = height[l];
                }
                l++;
            }   
            else{
                if(rightMax > height[r]){
                    total += rightMax - height[r];
                }
                else{
                    rightMax = height[r];
                }
                r--;
            }
        }

        return total;
    }
};


