#include<iostream>
using namespace std;

// Shortest path in Directed Acyclic Graph
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1


// finding shortest distance from source to all other nodes
// using topological sort

class Solution {
  public:
    void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it.first]){
                dfs(it.first, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int> >> adj(V, vector<pair<int,int>>());
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});       // node, weight
        }
        
        stack<int> st;
        vector<int> vis(V);
        
        dfs(0, adj, vis,st);
        
        vector<int> dis(V, 1e9);
        dis[0] = 0;
        
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            for(auto it : adj[top]){
                if(dis[top] + it.second < dis[it.first]){
                    dis[it.first] = dis[top] + it.second;
                }
            }
        }
        
        for(int i = 0; i<V; i++){
            if(dis[i] == 1e9){
                dis[i] = -1;
            }
        }
        
        
        return dis;
    }
};



