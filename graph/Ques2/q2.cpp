#include<iostream>
using namespace std;

// detect a cycle in directed graph
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


// DFS  --> use two visited arrays --> 1. Visited 2.Pathvisited
// If we find a node in the pathVisited array, then it's a cycle because this node belongs to the path that 
// we're currently traversing. But if it's not in the pathVisited array, it means we've already visited it,
//  but it's not part of the current path, so we can skip it.
// TC --> O(N + E)
// SC --> O(2N)
class Solution {
  public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int>&vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis))  return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V, vector<int>());
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        // we'll make two visited arrays
        // visited and Pathvisited, we'll backtrack the PathVisited array
        vector<int> vis(V);
        vector<int> pathVis(V);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis)){
                    return true;
                }
            }
        }
        return false;
    }
};
