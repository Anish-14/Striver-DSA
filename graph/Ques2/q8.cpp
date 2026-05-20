#include<iostream>
using namespace std;

// Course Schedule 2
// https://leetcode.com/problems/course-schedule-ii/description/


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     int V=numCourses;vector<vector<int>>adj(V);vector<int> topo;vector<int>indegree(V);
     for(auto edge:prerequisites){
        adj[edge[1]].push_back(edge[0]);
        indegree[edge[0]]++;
     }

     queue<int> q;
     for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
            topo.push_back(i);
        }
     }
     while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
                topo.push_back(it);
            }
        }
     }
     if(topo.size()==V){
        return topo;
     }
     else{
        return {};
     }
    }
};