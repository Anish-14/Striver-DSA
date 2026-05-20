#include<iostream>
using namespace std;
#include "syntax.h"

// Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


class Solution {
public:
    // if you want to improve the TC of this function then use map to get the indices instead 
    // of using a loop for that
    int getIndex(int val, vector<int> &inorder, int n){
        for(int i = 0; i<n; i++){
            if(inorder[i] == val){
                return i;
            }
        }

        return -1;
    }
    TreeNode* build(vector<int>& inorder, vector<int> &postorder, int &currIndex, int start, int end, int size){
        // base case
        if(start > end || currIndex < 0){
            return NULL;
        }

        int val = postorder[currIndex--];
        TreeNode* root = new TreeNode(val);

        int index = getIndex(val, inorder, size);

        root->right = build(inorder, postorder, currIndex, index+1, end, size);
        root->left = build(inorder, postorder, currIndex, start, index-1, size);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int currIndex = n-1;

        return build(inorder, postorder, currIndex, 0, n-1, n);
    }
};