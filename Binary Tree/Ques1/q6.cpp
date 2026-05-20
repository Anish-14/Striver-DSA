#include<iostream>
using namespace std;
#include "syntax.h"

//  maximum depth of Binary Tree
//  https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int leftLen = maxDepth(root->left);
        int rightLen = maxDepth(root->right);

        return max(leftLen, rightLen) + 1;
    }
};

