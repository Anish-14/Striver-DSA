#include<iostream>
using namespace std;
#include "syntax.h"

// Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/


class Solution {
public:
    // res stores the answer for the current node and this function returns 
    // the maxSum from either side including the root node
    int solve(TreeNode* root, int &res){    
        if(root == NULL){
            return 0;
        }

        int left = max(0, solve(root->left, res));
        int right = max(0, solve(root->right, res));

        res = max(res, left+right+root->val);       // this is the answer for the current node

        return max(left, right) + root->val;        // this is what function need to return for its parent for calculation

    }
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        solve(root, res);

        return res;
    }
};


// Without the reference res variable
class Solution {
public:
    pair<int,int> maxSum(TreeNode* root){
        if(root == NULL){
            return make_pair(0, INT_MIN);
        }

        auto left = maxSum(root->left);
        auto right = maxSum(root->right);

        // first variable stores the sum with either left or right path including the root
        int first = max(0, max(left.first, right.first)) + root->val;
        // second variable contains our answer
        int throughout = max(0, left.first) + max(0, right.first) + root->val;
        int second = max(left.second, max(right.second, throughout));

        return {first, second};
    }
    int maxPathSum(TreeNode* root) {
        return maxSum(root).second;
    }
};


