#include<iostream>
using namespace std;

// Bellman-Ford Algorithm
// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// Single-source shortest path (SSSP) algorithm on directed weighted graphs.
// Unlike Dijkstra, it works seamlessly with negative edge weights.
// It can detect negative weight cycles reachable from the source.

// shortest path from src to all the other nodes
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src){
        // V is nodes
        vector<int> dis(V, 1e8);
        dis[src] = 0;
        
        // perform relaxation of edges V-1 times
        for(int i = 0; i<V-1; i++){
            for(auto it : edges){
                if(dis[it[0]] != 1e8 && dis[it[0]] + it[2] < dis[it[1]]){
                    dis[it[1]] = dis[it[0]] + it[2];
                }
            }
        }
        
        for(auto it : edges){
            if(dis[it[0]] != 1e8 && dis[it[0]] + it[2] < dis[it[1]]){
                return {-1};
            }
        }
        
        return dis;
    }
};

// In any graph with V vertices containing no negative-weight cycles, 
// the shortest simple path between any two vertices can contain at most V - 1 edges.

