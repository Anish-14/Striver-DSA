#include<iostream>
using namespace std;
#include "syntax.h"

// Morris Traversal for Inorder traversal
// https://www.geeksforgeeks.org/problems/inorder-traversal/1


class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        Node* curr = root;
        
        while(curr != NULL){
            if(curr->left != NULL){
                Node* Left = curr->left;
                while(Left->right != NULL && Left->right != curr){
                    Left = Left->right;
                }
                Left->right = curr;
                Node* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
            else{
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
        
        return ans;
    }
};


// this is the morris traversal logic with making the Tree exactly same as before
// this approach is better and ideal

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        Node* curr = root;
        
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else{
                Node* Left = curr->left;

                while(Left->right != NULL && Left->right != curr){
                    Left = Left->right;
                }

                if(Left->right == NULL){
                    Left->right = curr;
                    curr = curr->left;
                }
                else{
                    Left->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};

