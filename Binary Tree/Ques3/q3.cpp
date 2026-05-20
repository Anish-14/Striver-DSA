#include<iostream>
using namespace std;
#include "syntax.h"

// Amount of Time for Binary Tree to Be Infected
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

class Solution {
public:
    TreeNode* target;
    void fillParent(TreeNode* root, TreeNode* parent, int start, unordered_map<TreeNode*, TreeNode*> &mp){
        if(root == NULL){
            return;
        }
        if(root->val == start){
            target = root;
        }
        mp[root] = parent;

        fillParent(root->left, root, start, mp);
        fillParent(root->right, root, start, mp);
    }

    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL){
            return 0;
        }

        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        fillParent(root, NULL, start, nodeToParent);

        int ans = 0;
        queue<pair<TreeNode*, int>> q;      // node, time
        q.push(make_pair(target, 0));
        unordered_map<TreeNode*, bool> vis;
        // vis[root] = 1;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int time = p.second;
            // cout<<"here for node --> "<<node->val<<endl;
            ans = max(ans, time);

            vis[node] = 1;

            if(node->left && !vis[node->left]){
                q.push(make_pair(node->left, time+1));
            }
            if(node->right && !vis[node->right]){
                q.push(make_pair(node->right, time+1));
            }
            if(nodeToParent[node] && !vis[nodeToParent[node]]){
                q.push(make_pair(nodeToParent[node], time+1));
            }
        }

        return ans;
    }
};

