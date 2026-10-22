#include<iostream>
using namespace std;

// M coloring problem
// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution {
  public:
    bool isSafe(vector<int> &color, vector<vector<int>> &adj, int node, int col){
        for(auto i : adj[node]){
            if(color[i] == col){
                return false;
            }
        }
        
        return true;
    }
    bool solve(vector<vector<int>> &adj, int v, int m, vector<int> &color, int node){
        // as it is zero based indexing so if v == node that means you've colored all the nodes correctly
        if(v == node){
            return true;
        }
        
        for(int i = 1; i<=m; i++){
            if(isSafe(color, adj, node, i)){
                color[node] = i;
                if(solve(adj, v, m, color, node+1)) return true;
                color[node] = -1;
            }
        }
        
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        for(int i = 0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> color(v, -1);
        return solve(adj, v, m, color, 0);
    }
};