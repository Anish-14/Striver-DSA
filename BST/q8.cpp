#include<iostream>
using namespace std;
#include "syntax.h"

// Construct Binary Search Tree from Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

// This problem is same as constructing a binary tree from pre and inorder traversal, the only catch here is to get that the 
// inorder traversal of a BST is always in a sorted order. We can get the inorder traversal by simply sorting the preorder

class Solution {
public:
    int n;
    int findIndex(vector<int> &in, int target, int s, int e){
        for(int i = s; i<=e; i++){
            if(in[i] == target){
                return i;
            }
        }

        return -1;
    }
    TreeNode* constructBST(vector<int> &pre, vector<int> &in, int sIndex, int eIndex, int &currIndex){
        if(currIndex >= n || sIndex > eIndex){
            return NULL;
        }

        TreeNode* root = new TreeNode(pre[currIndex]);
        int index = findIndex(in, pre[currIndex], sIndex, eIndex);
        currIndex++;

        root->left = constructBST(pre, in, sIndex, index-1, currIndex);
        root->right = constructBST(pre, in, index+1, eIndex, currIndex);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        int curr = 0;
        TreeNode* root = constructBST(preorder, inorder, 0, n-1, curr);

        return root;
    }
};




