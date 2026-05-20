#include<iostream>
using namespace std;
#include "syntax.h"

// Largest BST
// https://www.geeksforgeeks.org/problems/largest-bst/1

// Good problem 


// Brute force --> Go to every node and check whether it is a BST or not and then calculate its size if it is a BST and return
// the maximum size BST encountered.

// best solution --> TC:O(N) && SC:O(1)
class NodeValue{
  public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
class Solution {
  public:
    NodeValue helper(Node* root){
        if(root == NULL){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        // curr node is greater than max in left and smaller than min in right
        if(left.maxNode < root->data && root->data < right.minNode){
            // it is a bst
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    int largestBst(Node *root) {
        return helper(root).maxSize;
        
    }
};



