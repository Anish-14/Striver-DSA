#include<iostream>
using namespace std;
#include "syntax.h"

// Predecessor and Successor
// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

class Solution {
  public:
    void getPreSuc(Node* root, int key, vector<Node*> &ans){
        if(root == NULL){
            return;
        }
        
        if(root->data < key){
            ans[0] = root;
            getPreSuc(root->right, key, ans);
        }
        else if(root->data > key){
            ans[1] = root;
            getPreSuc(root->left, key, ans);
        }
        else{
            getPreSuc(root->left, key, ans);
            getPreSuc(root->right, key, ans);
        }
        
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans = {NULL, NULL};
        
        getPreSuc(root, key, ans);
        
        return ans;
    }
};

