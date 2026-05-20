#include<iostream>
using namespace std;
#include "syntax.h"

// Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// inorder traversal of a BST will be in sorted manner

class Solution {
public:
    void solve(TreeNode* root, int &ans, int &cnt, int k){
        if(root == NULL){
            return;
        }

        solve(root->left, ans, cnt, k);
        cnt++;

        if(cnt == k){
            ans = root->val;
            return;
        }

        solve(root->right, ans, cnt, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        int cnt = 0;
        solve(root, ans, cnt, k);

        return ans;
    }
};

