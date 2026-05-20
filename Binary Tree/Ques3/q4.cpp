#include<iostream>
using namespace std;
#include "syntax.h"

//  count number of nodes in a binary tree
//  https://leetcode.com/problems/count-complete-tree-nodes/description/

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0; 
        }

        int leftCnt = countNodes(root->left);
        int rightCnt = countNodes(root->right);

        return leftCnt + rightCnt + 1;
    }
};
