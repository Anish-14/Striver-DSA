#include<iostream>
using namespace std;

// Minimum Spanning Tree
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// Prim's Algorithm

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int> >> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> vis(V);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        
        q.push({0,0});       // weight, node
        int sum = 0;
        
        
        while(!q.empty()){
            int distance = q.top().first;
            int node = q.top().second;
            q.pop();
            if(!vis[node]){
                sum += distance;
                vis[node] = 1;
            }
            for(auto it : adj[node]){
                if(!vis[it.first]){
                    q.push({it.second,it.first});
                }
            }
        }
        
        return sum;
    }
};