#include<iostream>
using namespace std;
#include "syntax.h"

// The Boundary Traversal
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1


class Solution {
  public:
    void right(Node* root, vector<int> &ans){
        if(root == NULL ||(root->left == NULL && root->right == NULL)){
            return;
        }
        
        if(root->right){
            right(root->right, ans);
        }
        else{
            right(root->left, ans);
        }
        ans.push_back(root->data);
    }
    void leaf(Node* root, vector<int> &ans){
        if(root == NULL){
            return ;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
    void left(Node* root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return ;
        }
        ans.push_back(root->data);
        // left(root->left, ans);
        if(root->left){
            left(root->left, ans);
        }
        else{
            left(root->right, ans);
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        if(root->left == NULL && root->right == NULL){
            return {root->data};
        }
        ans.push_back(root->data);
        left(root->left, ans);
        leaf(root, ans);
        right(root->right, ans);
        
        return ans;
    }
};



