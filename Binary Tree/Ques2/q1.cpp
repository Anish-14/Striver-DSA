#include<iostream>
using namespace std;
#include "syntax.h"

// zig-zag traversal
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // level Order traversal i.e. BFS
        vector<vector<int>> ans;
        if(root == NULL)    return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool leftToRight = true;
        vector<int> temp;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(node == NULL){
                if(!leftToRight){
                    reverse(temp.begin(), temp.end());
                }
                leftToRight = !leftToRight;
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





