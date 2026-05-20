#include<iostream>
#include<set>
using namespace std;

// Cheapest Flights Within K Stops
// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/


// here the dijkstra's algorithm wil not work because of the condition of k stops, there may be a smaller path but that may 
// take more than k stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        vector<int> dis(n, 1e9);
        // priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > q;     // dis, node, stops
        queue<pair<int,pair<int,int>>> q;
        dis[src] = 0;
        q.push({0, {src, 0}});      // actually we are storing k-1 here at stop acc. to the question

        while(!q.empty()){
            int distance = q.front().first;
            int node = q.front().second.first;
            int prevStops = q.front().second.second;
            q.pop();

            for(auto it : adj[node]){
                if(prevStops + 1 <= k+1){       
                    if(distance + it.second < dis[it.first]){
                        cout<<"came here for "<<node<<" "<<it.first<<endl;
                        dis[it.first] = distance + it.second;
                        q.push({dis[it.first],{it.first, prevStops + 1}});
                    }
                }
            }
        }

        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};

