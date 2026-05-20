#include<iostream>
using namespace std;
#include "syntax.h"

// is tree Balanced  --> A balanced tree is a tree which has a maximum difference of height <= 1 for each node in the tree
// https://leetcode.com/problems/balanced-binary-tree/description/


class Solution {
public:
    pair<bool, int> heightBalance(TreeNode* root){
        if(root == NULL){
            return {true, 0};
        }

        pair<bool, int> leftAns = heightBalance(root->left);
        pair<bool, int> rightAns = heightBalance(root->right);

        pair<bool, int> ans = {0, 1};
        if(leftAns.first && rightAns.first && abs(leftAns.second - rightAns.second) <= 1){
            ans = make_pair(true, max(leftAns.second, rightAns.second) + 1);
        }

        return ans;        // return any garbage value for the height here
    }
    bool isBalanced(TreeNode* root) {
        return heightBalance(root).first;
    }
};








