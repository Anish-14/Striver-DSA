#include<iostream>
using namespace std;
#include "syntax.h"

// All Nodes Distance K in Binary Tree
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

class Solution {
public:
    void fillParent(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &mp){
        if(root == NULL){
            return;
        }

        mp[root] = parent;

        fillParent(root->left, root, mp);
        fillParent(root->right, root, mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        fillParent(root, NULL, nodeToParent);

        // start BFS from the target node
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, target));
        unordered_map<TreeNode*, bool> vis;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.second;
            int currDis = p.first;

            if(vis[node]){
                continue;
            }
            vis[node] = 1;

            if(currDis == k){
                ans.push_back(node->val);
                continue;
            }

            if(node->left){
                q.push(make_pair(currDis+1, node->left));
            }
            if(node->right){
                q.push(make_pair(currDis+1, node->right));
            }
            if(nodeToParent[node]){
                q.push(make_pair(currDis+1, nodeToParent[node]));
            }
        }

        return ans;
    }
};