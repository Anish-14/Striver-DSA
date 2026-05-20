#include<iostream>
using namespace std;

// Depth first search (DFS)
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    void dfs(int val, vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans){
        vis[val] = 1;
        ans.push_back(val);
        
        for(auto i : adj[val]){
            if(!vis[i]){
                dfs(i, adj, vis, ans);
            }
        }
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        vector<int> vis(n, 0);
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, vis, ans);
            }
        }
        
        return ans;
    }
};


