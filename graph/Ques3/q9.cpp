#include<iostream>
#include<set>
using namespace std;

// Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/description/

// Godd problem for dijkstra's algorithm understanding


// Using Dijkstra's algorithm 
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        // queue<pair<int, pair<int,int>>> q;      // history, x, y
        priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > q;

        q.push({0, {0, 0}});
        dis[0][0] = 0;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while(!q.empty()){
            int prevHis = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();

            for(int i = 0; i<4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                    int comp = max(prevHis, abs(heights[newx][newy] - heights[x][y]));
                    if(comp < dis[newx][newy]){
                        dis[newx][newy] = comp;
                        q.push({comp, {newx, newy}});
                    }
                }
            }
        }

        return dis[n-1][m-1];
    }
};


// Using only queue, but it'll be a bit slower than the above solution, as we won't be processing the nodes 
// in the order of their current shortest distance from the source node, but it'll still give the correct answer
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int,int>>> q;      // history, x, y

        q.push({0, {0, 0}});
        dis[0][0] = 0;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        while(!q.empty()){
            int prevHis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for(int i = 0; i<4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < n && newy >= 0 && newy < m){
                    int comp = max(prevHis, abs(heights[newx][newy] - heights[x][y]));
                    if(comp < dis[newx][newy]){
                        dis[newx][newy] = comp;
                        q.push({comp, {newx, newy}});
                    }
                }
            }
        }

        return dis[n-1][m-1];
    }
};



