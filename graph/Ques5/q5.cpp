#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Count Strongly Connected Components
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// Kosaraju Algo

// We'll take topo sort
// We'll reverse the edges
// Then we'll just traverse the graph with dfs as the components are seperated by now
// we needed the topo sort here and we can't just randomely start from anywhere because we don't 
// which SCC to start my traversal so that I'm blocked from entering the other SCC from everywhere 
// and this is important because this is the exact logic we're applying by reversing the edges.

// Remember : Topo sort uisng DFS pushes all nodes no matter if there's a cycle or not
// The BFS topo sort doesn't push all elements if there's a cycle
class Solution {
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        
        st.push(node);
    }
    void dfsFinal(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfsFinal(it, vis, adj);
            }
        }
    }
public:
    int countSCC(int V, vector<vector<int>> &edges) {
        // step 1 : traverse the graph and save the nodes in order of their
        // function call in DFS i.e. Topo Sort
        vector<vector<int>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        // Step 2 : 
        // we need to reverse the edges
        vector<vector<int>> adjT(V);
        for(int i = 0; i<V; i++){
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        

        // Step 3 : 
        // start bfs from the topo sort and count the SCC
        int scc = 0;
        vis = vector<int> (V, 0);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfsFinal(node, vis, adjT);
            }
        }
        
        return scc;
    }
};



