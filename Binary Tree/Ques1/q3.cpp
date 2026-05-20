#include<iostream>
using namespace std;
#include "syntax.h"

// postOrder traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/description/


// Recursive Method
class Solution {
public:
    void postOrder(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return;
        }

        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};


// Iterative Method using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)    return {};
        vector<int> ans;
        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);

            if(root->left){
                st1.push(root->left);
            }
            if(root->right){
                st1.push(root->right);
            }
        }

        while(!st2.empty()){
            TreeNode* node = st2.top();
            st2.pop();
            ans.push_back(node->val);
        }

        return ans;
    }
};

// Iterative solution using 1 stack --> think of it as just opposite of preOrder traversal
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)    return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            ans.push_back(node->val);

            if(node->left){
                st.push(node->left);
            }
            if(node->right){
                st.push(node->right);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// Iterative best solution using 1 stack and in O(N) TC
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)    return {};
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != NULL || !st.empty()){
            if(curr != NULL){           // go as left as possible
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = st.top()->right;       // if left is NULL then go just right and repeat if it is not NULL
                if(temp == NULL){                       // if the right is NULL too then we've to store it
                    temp = st.top();    
                    st.pop();
                    ans.push_back(temp->val);

                    while(!st.empty() && temp == st.top()->right){      // now if you are top's right then it mean the top should 
                        temp = st.top();                                // come just after you because it don't have any node so  
                        st.pop();                                       // take that and repeat
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        
        return ans;
    }
};

