#include<iostream>
using namespace std;

// Bellman-Ford Algorithm
// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1


// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dis(V, 1e8);
        dis[src] = 0;
        
        // perform relaxation of edges n-1 times
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









