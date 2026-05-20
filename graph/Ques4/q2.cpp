#include<iostream>
using namespace std;

// Number of Ways to Arrive at Destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

// Similar to Dijkstra's Algorithm

class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<pair<long long,long long>> dis(n, {1e18,0});
        priority_queue< pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > q;
        
        q.push({0, 0});     // dis, node
        dis[0] = {0,1};

        while(!q.empty()){
            long long distance = q.top().first;
            int node = q.top().second;
            q.pop();

            if(distance > dis[node].first) continue;

            for(auto it : adj[node]){
                if(distance + it.second < dis[it.first].first){
                    dis[it.first].first = distance + it.second;
                    dis[it.first].second = dis[node].second % mod;      // here we'll take all possibilities to reach this node, not just 1 possibility.
                    q.push({dis[it.first].first, it.first});
                }
                else if(distance + it.second == dis[it.first].first){
                    dis[it.first].second = (dis[it.first].second + dis[node].second) % mod;     // here also we're taking all possibilities to reach this node, not just 1 possibility.
                }
            }
        }

        return dis[n-1].second % mod;
    }
};


