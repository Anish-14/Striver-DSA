#include<iostream>
using namespace std;

// Floyd Warshall Algorithm
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// All-Pairs Shortest Path (APSP) algorithm.
// Finds the shortest distance between every pair of vertices (i, j) in a directed, weighted graph.
// Handles negative edge weights and can detect negative weight cycles.
// In a valid graph without negative cycles, dist[i][i] remains 0.

// dp[k][i][j] represents the shortest path between i & j taking 
// intermediate steps from this set of nodes {0,1,...k}
// the below is space optimised approach of this

// check paths i->k and k->j and update the path i->j if required
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // n are nodes
        int n = dist.size();
        
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8)   continue;  // if k is unreaachable from i or j is unreachable from k, then skip
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
    }
};
