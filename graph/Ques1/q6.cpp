#include<iostream>
using namespace std;

// Detect cycle in undirected graph
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// BFS Method
class Solution {
  public:
    bool bfs(int node, vector<int> &vis, vector<int> parent, vector<vector<int>> &adj){
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto it : adj[top]){
                if(vis[it] && parent[top] != it){
                    return true;
                }
                else if(!vis[it]){
                    vis[it] = 1;
                    parent[it] = top;
                    q.push(it);
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // bfs
        // we'll mark parent of each node and if we found any node in neighbour
        // that is visited and not parent then we've found the cycle in the graph
        
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(V, 0);
        vector<int> parent(V, -1);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(bfs(i, vis, parent, adj)){
                    return true;
                }
            }
        }
        
        return false;
    }
};



// DFS
class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &parent){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(vis[it] && parent[node] != it){
                return true;
            }
            else if(!vis[it]){
                parent[it] = node;
                if(dfs(it, adj, vis, parent)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> vis(V);
        vector<int> parent(V, -1);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, parent)){
                    return true;
                }
            }
        }
        
        return false;
    }
};




