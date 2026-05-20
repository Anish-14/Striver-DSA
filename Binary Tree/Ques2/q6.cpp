#include<iostream>
using namespace std;
#include "syntax.h"

// right side view
// https://leetcode.com/problems/binary-tree-right-side-view/description/

// its just the same problem as before just here we keep track of vertical distance instead of horizontal distance
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }

        map<int, TreeNode*> mp;     // vd, node
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int vd = p.first;
            TreeNode* node = p.second;

            if(mp.find(vd) == mp.end()){
                mp[vd] = node;
            }

            if(node->right){
                q.push({vd+1, node->right});
            }
            if(node->left){
                q.push({vd+1, node->left});
            }

        }

        for(auto p : mp){
            ans.push_back(p.second->val);
        }

        return ans;
    }
};




