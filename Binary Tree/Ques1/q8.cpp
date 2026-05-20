#include<iostream>
using namespace std;
#include "syntax.h"

// Diameter of a binary tree
// https://leetcode.com/problems/diameter-of-binary-tree/


class Solution {
public:
    pair<int,int> Dia(TreeNode* root){      // height, dia
        if(root == NULL){
            return make_pair(0,0);
        }

        auto leftDia = Dia(root->left);
        auto rightDia = Dia(root->right);

        pair<int,int> ans;
        ans.first = max(leftDia.first, rightDia.first) + 1;
        ans.second = max(leftDia.second, max(rightDia.second, leftDia.first + rightDia.first + 1));

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return Dia(root).second - 1;
    }
};
