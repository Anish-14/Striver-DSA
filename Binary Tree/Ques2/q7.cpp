#include<iostream>
using namespace std;
#include "syntax.h"

// Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/description/

class Solution {
public:
    bool check(TreeNode* r1, TreeNode* r2){
        if((r1 && !r2) || (!r1 && r2)){
            return false;
        }
        if(!r1 && !r2){
            return true;
        }

        if(r1->val != r2->val){
            return false;
        }

        bool first = check(r1->left, r2->right);
        bool second = check(r1->right, r2->left);

        if(first && second){
            return true;
        }

        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        return check(root->left, root->right);
    }
};