#include<iostream>
using namespace std;
#include "syntax.h"

// Preorder traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/description/ 


// Recursive solution 
class Solution {
public:
    void preOrder(TreeNode* root, vector<int> &vec){
        if(root == NULL){
            return;
        }

        vec.push_back(root->val);
        preOrder(root->left, vec);
        preOrder(root->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root, ans);

        return ans;
    }
};


// Iterative solution 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);
            
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }

        return ans;
    }
};
