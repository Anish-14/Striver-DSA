#include<iostream>
using namespace std;

// Course Schedule
// https://leetcode.com/problems/course-schedule/description/

// if there's a cycle in the graph then we can't complete all the courses, in that case we'll take 1 less course 
// In a way this is similar to detecting a cycle in a directed graph



class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, int &cnt, vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, cnt, vis, pathVis)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // dfs
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> pathVis(numCourses);
        vector<int> vis(numCourses);
        int cnt = 0;
        vector<int> topo;


        for(int i = 0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, cnt, vis, pathVis)){
                    return false;                       // if we find a loop then we can't take all the courses
                }
            }
        }

        return true;
    }
};

