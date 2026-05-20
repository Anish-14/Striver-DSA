#include<iostream>
using namespace std;

// find the number of provinces
// https://leetcode.com/problems/number-of-provinces/

// there is a better solution than this approach, in that we do the union by rank shit and get our answer.
// Do check out that approach too. That solution will give us top 100% solution

class Solution {
public:
    void dfs(int val, vector<vector<int>>& adj, vector<int> &vis){
        vis[val] = 1;

        for(auto i : adj[val]){
            if(!vis[i]){
                dfs(i, adj, vis);
            }
        }
    }
    int solve(vector<vector<int>>& adj){
        int ans = 0;
        int n = adj.size();
        vector<int> vis(n);

        for(int i = 1; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(i, adj, vis);
            }
        }

        return ans;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n+1);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j)  continue;
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1); 
                }
            }
        }

        return solve(adj);
    }
};
