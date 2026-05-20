#include<iostream>
#include<set>
using namespace std;

// printing the shortest distance path using dijkstra's algorithm
// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/0


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> dis(n+1, 1e9);
        dis[1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0, 1});
        vector<int> parent(n+1, -1);        // this will be needed to pring the path
        parent[1] = 1;
        
        
        while(!pq.empty()){
            auto top = pq.top();
            int distance = top.first;
            int node = top.second;
            pq.pop();
            
            if(distance > dis[node])    continue;
            
            for(auto it : adj[node]){
                if(distance + it.second < dis[it.first]){
                    dis[it.first] = distance + it.second;
                    parent[it.first] = node;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        
        if(dis[n] == 1e9)   return {-1};
        
        vector<int> ans;
        
        int i = n;                  // saving the path here
        while(parent[i] != i){
            ans.push_back(i);
            i = parent[i];
        }
        ans.push_back(i);
        ans.push_back(dis[n]);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};


