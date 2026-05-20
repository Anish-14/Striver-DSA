#include<iostream>
using namespace std;
#include "syntax.h"


// floor of a BST --> node of the BST which is smaller than or equal to x.
// https://www.geeksforgeeks.org/problems/floor-in-bst/1


class Solution {
  public:
    void solve(Node* root, int x, int &ans){
        if(root == NULL){
            return;
        }
        
        if(root->data == x){
            ans = x;
            return;
        }
        else if(root->data < x){
            ans = root->data;
            solve(root->right, x, ans);
        }
        else{
            solve(root->left, x, ans);
        }
    }
    int floor(Node* root, int x) {
        int ans = -1;
        solve(root, x, ans);
        
        return ans;
    }
};

