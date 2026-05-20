#include<iostream>
using namespace std;

// Bipartite Graph
// https://leetcode.com/problems/is-graph-bipartite/description/ 

// Bipartite Graph --> In an undirected graph if you can color them by two colors such that no two colors are adjacent to each 
// other than that graph can be called bipartite graph


// BFS
// TC --> O(N + E)
// SC --> O(N)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // BFS
        int n = graph.size();
        vector<int> vis(n);
        vector<int> color(n);       // 0 and 1
        queue<int> q;
        

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                q.push(i);     
                vis[i] = 1;

                while(!q.empty()){
                    int top = q.front();
                    q.pop();

                    for(auto it : graph[top]){
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                            color[it] = !color[top];        // give it opposite color
                        }
                        else if(color[it] == color[top]){   // if color of it and top is same then it is not bipartite
                            return false;
                        }
                    }
                }
            }
             
        }

        return true;
    }
};



// DFS
// TC --> O(N + E)
// SC --> O(N)
class Solution {
public:
    // DFS
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &color){
        vis[node] = 1;

        for(auto it : graph[node]){
            if(!vis[it]){
                color[it] = !color[node];
                if(!dfs(it, graph, vis, color)){
                    return false;
                }
            }
            else if(color[it] == color[node]){
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n);
        vector<int> color(n);  

        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(!dfs(i, graph, vis, color)){
                    return false;
                }
            }
        }

        return true;
    }
};

