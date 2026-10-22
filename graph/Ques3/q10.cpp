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
        // we've to take cost till now with queue because the distance is constantly changing
        queue<pair<int,pair<int,int>>> q;   // cost, node, stops
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
                        // cout<<"came here for "<<node<<" "<<it.first<<endl;
                        dis[it.first] = distance + it.second;
                        q.push({dis[it.first], {it.first, prevStops + 1}});
                    }
                }
            }
        }

        if(dis[dst] == 1e9) return -1;
        return dis[dst];
    }
};






// if exactly k stops is asked
class Solution {
public:
    int findCheapestPriceExactK(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        int targetEdges = k + 1; // exactly k stops = k + 1 edges

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // dis[node][stops]: min cost to reach `node` with EXACTLY `stops` edges
        vector<vector<int>> dis(n, vector<int>(targetEdges + 1, INF));

        // Queue stores: {current_cost, {current_node, edges_used}}
        queue<pair<int, pair<int, int>>> q;

        dis[src][0] = 0;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto [cost, state] = q.front();
            auto [node, edges] = state;
            q.pop();

            // Skip stale states
            if (cost > dis[node][edges]) continue;

            // Cannot take any more edges
            if (edges == targetEdges) continue;

            for (const auto& [next_node, price] : adj[node]) {
                int next_edges = edges + 1;
                if (cost + price < dis[next_node][next_edges]){
                    dis[next_node][next_edges] = cost + price;
                    q.push({dis[next_node][next_edges], {next_node, next_edges}});
                }
            }
        }

        return dis[dst][targetEdges] == INF ? -1 : dis[dst][targetEdges];
    }
};


// dp version
class Solution {
public:
    int findCheapestPriceExactK(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<int> dp(n, INF);
        dp[src] = 0;

        // Exactly k stops means exactly k + 1 edges/flights
        int targetEdges = k + 1;

        for (int step = 1; step <= targetEdges; ++step) {
            // temp stores the minimum cost using EXACTLY 'step' edges
            vector<int> temp(n, INF);

            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];

                // If u was reachable in the previous step (exactly step - 1 edges)
                if (dp[u] != INF) {
                    temp[v] = min(temp[v], dp[u] + cost);
                }
            }

            dp = move(temp);
        }

        return dp[dst] == INF ? -1 : dp[dst];
    }
};

