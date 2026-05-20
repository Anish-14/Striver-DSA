#include<iostream>
using namespace std;
#include "syntax.h"

// search in a BST
// https://leetcode.com/problems/search-in-a-binary-search-tree/



class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == val){
            return root;
        }
        else if(root->val > val){           // go search in left subtree
            return searchBST(root->left, val);
        }
        else{
            return searchBST(root->right, val);     // go search in right subtree
        }
    }
};


