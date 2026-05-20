#include<iostream>
using namespace std;

// Topological sort using DFS
// https://www.geeksforgeeks.org/problems/topological-sort/1

// Definition --> every node should come before all the nodes it points to in topo sort vector
// Application --> to find the order of compilation of files in a project

// Approach --> We traverse the graph using DFS and push the node in the stack when we complete the traversal of the node and when
// the function call is over then we push the node in the stack. This way we get the topological sort of the graph in reverse order
// stored in stack. So our order is up to down in the stack. So we pop the elements from the stack and store it in the vector.

// DFS  
class Solution {
  public:   
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // DFS
        vector<vector<int>> adj(V, vector<int>());
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> vis(V);
        stack<int> st;
        vector<int> v;
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        
        return v;
    }
};