#include<iostream>
using namespace std;
#include "syntax.h"

// two sum in BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

// Brute Force --> 

// find the inorder of the BST, now we have a sorted array. We can easily apply the two sum logic here and find the answer in O(2N) TC. (one for inorder and one for two sum)
// The SC --> O(N) to store the N nodes


// Best Solution --> TC:O(N) and SC:O(2H)
// this class alone can make two different objects that'll give us the next and before values
class BSTIterator {
    void pushAll(TreeNode* node){
        for(; node != NULL;){
            myStack.push(node);
            if(reverse){
                node = node->right;
            }
            else{
                node = node->left;
            }
        }
    }
public:
    stack<TreeNode*> myStack;
    // reverse --> true --> before
    // reverse --> false --> next
    bool reverse = true;
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* tempNode = myStack.top();
        myStack.pop();
        if(!reverse)    pushAll(tempNode->right);
        else pushAll(tempNode->left);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !myStack.empty();
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)   return false;
        BSTIterator l(root, false);     // this gives us the element in increasing order
        BSTIterator r(root, true);      // this gives us the element in decreasing order

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i + j == k)  return true;
            else if(i + j < k)  i = l.next();
            else    j = r.next();
        }

        return false;
    }
};