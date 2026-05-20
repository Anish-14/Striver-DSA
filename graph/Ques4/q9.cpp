#include<iostream>
#include<vector>
using namespace std;

// Number of provinces using disjoint set
// https://www.geeksforgeeks.org/problems/number-of-provinces/1


class Solution {
  public:
    vector<int> parent, rank;
    int getParent(int a, vector<int> &parent){
        if(parent[a] == a)  return a;
        return parent[a] = getParent(parent[a], parent);
    }
    void unionByRank(int a, int b, vector<int> &parent, vector<int> &rank){
        int para = getParent(a, parent);
        int parb = getParent(b, parent);
        
        if(para == parb)    return;
        
        if(rank[para] < rank[parb]){
            parent[para] = parb;
        }
        else if(rank[para] > rank[parb]){
            parent[parb] = para;
        }
        else{
            parent[parb] = para;
            rank[para]++;
        }
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        parent.resize(V+1);
        rank.resize(V+1, 0);
        
        for(int i = 1; i<=V; i++){
            parent[i] = i;
        }
        
        for(int i = 0; i<adj.size(); i++){
            for(int j = 0; j<adj[i].size(); j++){
                if(adj[i][j] == 1){
                    unionByRank(i+1, j+1, parent, rank);
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i<=V; i++){
            int pari = getParent(i, parent);
            if(pari == i)   ans++;
        }
        
        return ans;
    }
};





