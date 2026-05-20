#include<iostream>
using namespace std;
#include "syntax.h"

// https://leetcode.com/problems/maximum-width-of-binary-tree/description/
// Maximum Width of Binary Tree

// Good Problem

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push(make_pair(root, 0));
        unsigned long long int ans = 0;

        while(!q.empty()){
            int size = q.size();
            auto left = q.front().second;
            auto right = q.back().second;
            ans = max(ans, right - left + 1);

            for(int i = 0; i<size; i++){
                TreeNode* curr = q.front().first;
                auto index = q.front().second - left;
                q.pop();

                if(curr->left){
                    q.push(make_pair(curr->left, 2*index+1));
                }
                if(curr->right){
                    q.push(make_pair(curr->right, 2*index + 2));
                }
            }
        }

        return int(ans);
    }
};




