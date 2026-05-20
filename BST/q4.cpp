#include<iostream>
using namespace std;
#include "syntax.h"

// Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/description/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }

        if(root->val == key){
            if(root->left == NULL && root->right == NULL)   return NULL;
            if(root->left){ // go find the biggest node in left subtree and replace it with this node
                TreeNode* temp = root->left;
                while(temp->right != NULL){
                    temp = temp->right;
                }
                int number = temp->val;
                temp->val = root->val;
                root->val = number;
                root->left = deleteNode(root->left, key);
            }else{
                TreeNode* temp = root->right;
                while(temp->left != NULL){
                    temp = temp->left;
                }
                int number = temp->val;
                temp->val = root->val;
                root->val = number;
                root->right = deleteNode(root->right, key);    
            }
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key); 
        }
        else{
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};



