#include<iostream>
using namespace std;

// BFS --> Breadth First Search
// A graph traversal algorithm


// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// BFS traversal

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        queue<int> q;
        vector<int> vis(n);
        q.push(0);
        vis[0] = 1;
        
        vector<int> ans;
        
        while(!q.empty()){
            int num = q.front();
            q.pop();
            
            ans.push_back(num);
            
            for(auto i : adj[num]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        
        return ans;
    }
};
