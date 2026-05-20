#include<iostream>
using namespace std;

// Shortest Path in Undirected Graph
// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

// Using simple BFS

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V, vector<int>());
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> dis(V, 1e9);
        
        queue<int> q;
        vector<int> vis(V);
        q.push(src);
        dis[src] = 0;
        vis[src] = 1;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto it : adj[top]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                    dis[it] = dis[top] + 1;
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
