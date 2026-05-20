#include<iostream>
using namespace std;

// Dijkstra's algorithm
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Using Priority queue 

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> dis(V, 1e9);
        dis[src] = 0;
        pq.push({0, src});      //dist, node  // dist will be the first element, it'll be sorted based on the distance

        while(!pq.empty()){
            auto top = pq.top();
            int node = top.second;
            int distance = top.first;
            pq.pop();
            
            // slight optimization, 
            // here we're skipping the nodes which are pushed multiple times in the priority queue and 
            // is reached through a lesser distance than the one which is currently being processed
            if(distance > dis[node])    continue;       
            
            for(auto it : adj[node]){
                if(distance + it.second < dis[it.first]){
                    dis[it.first] = distance + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }
        
        return dis;
    }
};


// Why PQ and not queue --> 

// Dijkstra's algorithm is a greedy algorithm that relies on processing nodes in order of their 
// current shortest distance from the source node.
// In Dijkstra's algorithm, we need to always process the node with the smallest distance first.
// A priority queue allows us to efficiently retrieve the node with the smallest distance,
// whereas a regular queue would process nodes in the order they were added, which may not be optimal for Dijkstra's algorithm.





