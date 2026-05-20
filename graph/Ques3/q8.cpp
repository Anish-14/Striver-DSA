#include<iostream>
#include<set>
using namespace std;


// Shortest Path in Binary Matrix
// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/=





class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dis[0][0] = 0;
        q.push({0, {0, 0}});       // dis, x, y
        vis[0][0] = 1;

        vector<int> dx = {-1, 0, 1, 0, -1, 1, -1, 1};
        vector<int> dy = {0, -1, 0, 1, 1, -1, -1, 1};

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)  return -1;

        while(!q.empty()){
            int distance = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for(int i = 0; i<8; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == 0
                && !vis[newx][newy]){
                    dis[newx][newy] = distance + 1;
                    q.push({dis[newx][newy],{newx, newy}});
                    vis[newx][newy] = 1;
                }
            }
        }

        if(dis[n-1][m-1] == 1e9)  return -1;
        return dis[n-1][m-1] + 1;
    }
};



