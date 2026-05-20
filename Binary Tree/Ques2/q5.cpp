#include<iostream>
using namespace std;
#include "syntax.h"

// Bottom view of a binary tree
// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if(!root)   return ans;
        
        map<int, Node*> mp;       // hd, node
        
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            mp[p.first] = p.second;
            
            if(p.second->left){
                q.push(make_pair(p.first-1, p.second->left));
            }
            if(p.second->right){
                q.push(make_pair(p.first+1, p.second->right));
            }
        }
        
        for(auto p : mp){
            ans.push_back(p.second->data);
        }
      
        return ans; 
    }
};



