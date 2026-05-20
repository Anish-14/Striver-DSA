#include<iostream>
using namespace std;

// Kahn's Algorithm

// Topological sort using BFS
// https://www.geeksforgeeks.org/problems/topological-sort/1

// Indegree --> Number of edges coming into a node

// Approach --> we traverse the graph using BFS and push the node in the queue if the indegree of the node is 0. We then traverse the
// adjacency list of the node and decrement the indegree of the adjacent nodes. If the indegree of the adjacent node becomes 0, we push
// it in the queue. We repeat this process until the queue is empty. The order in which we pop the nodes from the queue is the
// topological sort of the graph. because we are pushing those nodes which have no incoming edges and then we are removing the edges
// from the graph and pushing the nodes which have no incoming edges in the queue.

// Kahn's Algorithm  
class Solution {
  public:   
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V, vector<int>());
        vector<int> indegree(V);
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
        
        vector<int> topo;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            topo.push_back(top);
            
            for(auto it : adj[top]){
                indegree[it]--;
                if(indegree[it] == 0)   q.push(it);
            }
        }
        
        return topo;
    }
};
