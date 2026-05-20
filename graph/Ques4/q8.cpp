#include<iostream>
#include<vector>
using namespace std;

// kruskal's algorithm
// minimum spanning tree
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// We solved it using disjoint set class

class Solution {
  public:
    vector<int> parent, rank;
    int getParent(int a, vector<int> &parent){
        if(parent[a] == a)  return a;
        return parent[a] = getParent(parent[a], parent);
    }
    void unionByRank(int a, int b, vector<int> &parent, vector<int> &rank){
        int parA = getParent(a, parent);
        int parB = getParent(b, parent);
        
        if(parA == parB)    return;
        
        if(rank[parA] < rank[parB]){
            parent[parA] = parB;
        }
        else if(rank[parA] > rank[parB]){
            parent[parB] = parA;
        }
        else{
            parent[parB] = parA;
            rank[parA]++;
        }
    }
    bool isConnected(int x, int y, vector<int> &parent) {
        int parx = getParent(x, parent);
        int pary = getParent(y, parent);
        
        if(parx == pary){
            return true;
        }
        return false;
    }
    int spanningTree(int V, vector<vector<int>>& edges) {
        parent.resize(V);
        rank.resize(V);
        for(int i = 0; i<V; i++){
            parent[i] = i;
        }
        
        for(int i = 0; i<edges.size(); i++){
            swap(edges[i][0], edges[i][2]);
        }
        
        sort(edges.begin(), edges.end());
        int ans = 0;
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][2];
            int v = edges[i][1];
            int w = edges[i][0];
            
            if(!isConnected(u, v, parent)){
                unionByRank(u, v, parent, rank);
                ans += w;
            }
        }
        
        return ans;
    }
};



