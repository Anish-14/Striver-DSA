#include<iostream>
using namespace std;
#include "syntax.h"

// Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/description/


// My brute solution
class BSTIterator {
public: 
    TreeNode* root = NULL;
    TreeNode* ans = NULL;
    int maxi = 0;
    int val = -1;

    void successor(TreeNode* root, int key, TreeNode* &ans){
        if(root == NULL){
            return ;
        }

        if(root->val > key){
            ans = root;
            successor(root->left, key, ans);
        }
        else if(root->val < key){
            successor(root->right, key, ans);
        }
        else{
            successor(root->left, key, ans);
            successor(root->right, key, ans);
        }
    }
    BSTIterator(TreeNode* root) {
        this->root = root;

        TreeNode* temp = root;
        if(temp == NULL){
            maxi = 0;
        }
        maxi = temp->val;
        while(temp->right != NULL){
            maxi = temp->right->val;
            temp = temp->right;
        }
    }
    
    int next() {
        successor(root, val, ans);
        
        val = ans->val;     // update it for next time
        return ans->val;
    }
    
    bool hasNext() {
        if(val == maxi){
            return false;
        }
        return true;
    }
};


// Best Solution TC --> O(1) && SC --> O(H)      H : height of binary tree
class BSTIterator {
    void pushAll(TreeNode* root){
        TreeNode* node = root;
        while(node != NULL){
            myStack.push(node);
            node = node->left;
        }
    }
public:
    stack<TreeNode*> myStack;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};

