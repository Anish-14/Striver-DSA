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


// for complete binary tree this is more optimal solution which runs in O((logn)^2)
class Solution {
public:
    int getLeftHeight(TreeNode* root){
        int cnt = 0;
        while(root != NULL){
            cnt++;
            root = root->left;
        }

        return cnt;
    }
    int getRightHeight(TreeNode* root){
        int cnt = 0;
        while(root != NULL){
            cnt++;
            root = root->right;
        }

        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL)    return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        if(lh == rh)    return (1<<lh) - 1;

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

