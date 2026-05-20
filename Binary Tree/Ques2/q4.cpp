#include<iostream>
using namespace std;
#include "syntax.h"

// Top View of Binary Tree
// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1


class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(!root)   return ans;
        
        map<int, Node*> mp;       // hd, node
        
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            if(mp.find(p.first) == mp.end()){
                mp[p.first] = p.second;
            }
            
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

