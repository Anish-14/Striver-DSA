#include<iostream>
using namespace std;
#include "syntax.h"
 
// Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/description/

class Solution {
public:
    vector<string> ans;
    TreeNode* node;
    void solve(TreeNode* root, string temp){
        if(root == NULL){
            return;
        }
        
        // push in the temp
        if(temp == ""){
            temp = temp + to_string(root->val);
        }
        else{
            temp = temp + "->" + to_string(root->val);
        }

        if(root->left == NULL && root->right == NULL){
            ans.push_back(temp);
            return;
        }

        solve(root->left, temp);
        solve(root->right, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp = "";
        if(root == NULL){
            return ans;
        }
        // temp = temp + (to_string(root->val));
        node = root;

        solve(root, temp);

        return ans;
    }
};



