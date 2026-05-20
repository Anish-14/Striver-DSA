#include<iostream>
using namespace std;
#include "syntax.h"

// inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

// Recursive Method
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);

        return ans;
    }
};


// Iterative Method
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)    return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty())  break;
                TreeNode* curr = st.top();
                st.pop();
                
                ans.push_back(curr->val);

                node = curr->right;
            }
        }

        return ans;
    }
};

