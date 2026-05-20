#include<iostream>
using namespace std;
#include "syntax.h"

// Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        // q.push(NULL);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL){
                ans.push_back('#');
                ans.push_back(' ');
                continue;
            }

            ans = ans + to_string(node->val) + " ";

            q.push(node->left);
            q.push(node->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)    return NULL;
        
        stringstream ss(data);
        string val;

        getline(ss, val, ' ');             // This function puts the token in the 'val' variable and returns true/false based on if it was able to tokenize or not
        if(val == "#")  return NULL;        // if first value is "#" then it mean it is null

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            // left
            if(!getline(ss, val, ' '))  break;
            if(val != "#"){
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }

            // right
            if(!getline(ss, val, ' '))  break;
            if(val != "#"){
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

