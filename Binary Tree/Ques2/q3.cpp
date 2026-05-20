#include<iostream>
#include<map>
#include<set>
using namespace std;
#include "syntax.h"

//  vertical order traversal
//  https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Good question 
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;            // here multiset is kind of set but it allows duplicate values, 
        queue<pair<TreeNode*, pair<int,int>>> q;            // and sorts the number coming to it as the set do.
        q.push({root, {0,0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);

            if(node->left){
                q.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                q.push({node->right, {x+1, y+1}});
            }
        } 

        vector<vector<int>> ans;            // we are copying each column in ans
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                // for(int val : q.second){
                //     col.push_back(val);
                // }
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};
