#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Articulation Point in graph
// https://www.geeksforgeeks.org/problems/articulation-point2616/1

class Solution {
  public:
    int timer = 0;
    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low,
        vector<int> &mark, vector<vector<int>> &adj){
        
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        int child = 0;
        for(auto it : adj[node]){
            if(it == parent)    continue;
            if(!vis[it]){
                child++;
                dfs(it, node, vis, tin, low, mark, adj);
                // we'll take the low
                low[node] = min(low[node], low[it]);
                
                // check for articulation point
                // here as the node is going to be erased therefore on equal to condition also
                // it can be the articulation point
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
            }
            else{
                low[node] = min(low[node], tin[it]);
            }
        }
        
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(V, 0);
        vector<int> tin(V, 0);
        vector<int> low(V, 0);
        vector<int> mark(V, 0);
        
        // dfs call
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i<V; i++){
            if(mark[i] != 0){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {-1};
        return ans;
    }
};
