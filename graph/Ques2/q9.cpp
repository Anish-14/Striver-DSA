#include<iostream>
using namespace std;

//  Eventual safe state
//  https://leetcode.com/problems/find-eventual-safe-states/description/

// BFS Method, used kahn's algorithm
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> adj(v);
        vector<int> indegree(v);
        vector<int> ans;
        for(int i = 0; i<v; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        // mark indegree
        for(int i = 0; i<v; i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(auto it : adj[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    ans.push_back(it);  
                }
            }
        }


        sort(ans.begin(), ans.end());
        return ans;
    }
};



