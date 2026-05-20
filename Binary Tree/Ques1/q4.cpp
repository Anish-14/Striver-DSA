#include<iostream>
using namespace std;
#include "syntax.h"

// Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL){
                ans.push_back(temp);
                temp.clear();

                if(q.empty()){
                    break;
                }
                q.push(NULL);
                continue;
            }

            temp.push_back(node->val);

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }

        return ans;
    }
};
