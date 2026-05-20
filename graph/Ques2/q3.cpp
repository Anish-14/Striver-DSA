#include<iostream>
using namespace std;

// Eventual safe states
// https://leetcode.com/problems/find-eventual-safe-states/description/


// DFS
class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;            // 0 means this can't be part of the vector

        for(auto it : graph[node]){
            if(!vis[it]){
                if(dfs(it, graph, vis, pathVis, check)){
                    return true;        // true means this can't be part of the vector 
                }
            }
            else if(pathVis[it]){       // this is the cycle detection condition
                return true;
            }
        }

        check[node] = 1;        // 1 means this can be part of the vector
        pathVis[node] = 0;      // backtracking
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n);
        vector<int> pathVis(n);
        vector<int> check(n);
        vector<int> ans;

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis, check);
            }
        }

        for(int i = 0; i<n; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};



