#include<iostream>
using namespace std;
#include "syntax.h"

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// Construct Binary Tree from Preorder and Inorder Traversal

class Solution {
public:
    int getIndex(vector<int> &inorder, int target, int sIndex, int eIndex){
        for(int i = sIndex; i<=eIndex; i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
    }
    TreeNode* make_Tree(vector<int> &preorder, vector<int> &inorder, int sIndex, int eIndex, int &currIndex){
        if(sIndex > eIndex || currIndex >= preorder.size()){
            return NULL;
        }

        TreeNode* newNode = new TreeNode(preorder[currIndex]);

        int index = getIndex(inorder, preorder[currIndex++], sIndex, eIndex);

        newNode->left = make_Tree(preorder, inorder, sIndex, index-1, currIndex);
        newNode->right = make_Tree(preorder, inorder, index+1, eIndex, currIndex);

        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int currIndex = 0;
        return make_Tree(preorder, inorder, 0, n-1, currIndex);
    }
};
