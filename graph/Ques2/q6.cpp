#include<iostream>
using namespace std;

// detect a cycle in directed graph
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


// Detecting cycle in directed graph using Kahn's Algorithm
// Approach --> we'll find the toposort vector and it should contain V elements if there's no cycles in the graph


class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V, vector<int>());
        vector<int> indegree(V);
        vector<int> topo;
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            } 
        }
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            topo.push_back(top);
            
            for(auto it : adj[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(topo.size() == V){
            return false;
        }
        
        return true;
    }
};



