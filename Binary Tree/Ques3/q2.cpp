#include<iostream>
using namespace std;
#include "syntax.h"

// Children Sum in a Binary Tree
// https://www.geeksforgeeks.org/problems/children-sum-parent/1


class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return true;
        }
        
        bool leftAns = isSumProperty(root->left);
        bool rightAns = isSumProperty(root->right);
        
        int sum = 0;
        if(root->left){
            sum += root->left->data;
        }
        if(root->right){
            sum += root->right->data;
        }
        
        if(sum == root->data && leftAns && rightAns){
            return true;
        }
        
        return false;
    }
};