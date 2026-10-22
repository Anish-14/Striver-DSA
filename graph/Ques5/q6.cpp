#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Tarjan's Algo

// Bridges in Graph --> Tarjan's Algo with low and in time
// https://leetcode.com/problems/critical-connections-in-a-network/description/

// tin --> time needed to reach the node
// low --> min time from all the adjacent nodes except parent

class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, vector<int> &low, vector<int> &tin, vector<vector<int>> &adj, vector<vector<int>> &bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for(auto it : adj[node]){
            if(it == parent)    continue;
            if(!vis[it]){
                dfs(it, node, vis, low, tin, adj, bridges);
                // we came back now take the low time 
                low[node] = min(low[node], low[it]);

                // check whether this can be a bridge or not
                if(low[it] > tin[node]){
                    bridges.push_back({node, it});
                }
            }
            else{
                // if it is already vis then it can't be bridge but we'll take the low though
                // here it also works if we take tin[it] 
                // tin[it] is the standard as it works for the articulation point problem as well
                low[node] = min(low[node], low[it]);
            }
        }    
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i = 0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> vis(n, 0);
        vector<int> low(n, 0);
        vector<int> tin(n, 0);

        vector<vector<int>> bridges;
        dfs(0, -1, vis, low, tin, adj, bridges);

        return bridges;
    }
};


