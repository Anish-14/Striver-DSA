#include<iostream>
using namespace std;
#include "syntax.h"


// Flatten Binary Tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

class Solution {
public:
    TreeNode* solve(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return root;
        }

        TreeNode* left = solve(root->left);
        TreeNode* right = solve(root->right);

        if(root->left == NULL){
            return root;
        }

        TreeNode* leftMost = root->left;
        while(leftMost->right){
            leftMost = leftMost->right;
        }

        leftMost->right = root->right;
        root->right = left;
        root->left = NULL;

        return root;
    }

    void flatten(TreeNode* root) {
        solve(root);
    }
};



