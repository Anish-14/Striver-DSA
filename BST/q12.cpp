#include<iostream>
using namespace std;
#include "syntax.h"

// Recover Binary Search Tree
// https://leetcode.com/problems/recover-binary-search-tree/description/

class Solution {
public:
    TreeNode *prev, *first, *middle, *last;
    void inorder(TreeNode* root){
        if(root == NULL)    return;
        
        inorder(root->left);

        if(prev != NULL && (root->val < prev->val)){    // the inorder is not sorted, so we found our error
            // is it the first error or second one
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);

        if(first && last)   swap(first->val, last->val);
        else if(first && middle)    swap(first->val, middle->val);
    }
};

