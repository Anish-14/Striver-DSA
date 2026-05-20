#include<iostream>
using namespace std;
#include "syntax.h"

// Ceil in BST -->  Ceil(x) is a number that is either equal to x or is immediately greater than x.
// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

class Solution {
  public:
    void find(Node* root, int x, int &ans){
        if(root == NULL){
            return ;
        }
        
        if(root->data == x){
            ans = root->data;
            return;
        }
        else if(root->data > x){        // this might be our answer so save it for now
            ans = root->data;
            find(root->left, x, ans);
        }
        else{
            find(root->right, x, ans);
        }
    }
    int findCeil(Node* root, int x) {
        int ans = -1;
        
        find(root, x, ans);
        
        return ans;
    }
};



