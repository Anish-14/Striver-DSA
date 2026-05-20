#include<iostream>
#include<set>
using namespace std;

// Dijkstra's algorithm
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Using set    

// better than priority queue, as it doesn't allow duplicate entries, so we don't have to do 
// the optimization of skipping the nodes which are pushed multiple times in the priority queue 
// and is reached through a lesser distance than the one which is currently being processed


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
    set<pair<int,int>> st;      // we can't use unordered_set here, as we need the data in sorted order
        vector<int> dis(V, 1e9);
        dis[src] = 0;
        st.insert({0, src});     // dis, node
        
        while(!st.empty()){
            auto top = *(st.begin());
            int node = top.second;
            int distance = top.first;
            st.erase(top);
            
            for(auto it : adj[node]){
                if(distance + it.second < dis[it.first]){
                    dis[it.first] = distance + it.second;
                    st.insert({dis[it.first], it.first});
                }
            }
        }
        
        return dis;
    }
};

