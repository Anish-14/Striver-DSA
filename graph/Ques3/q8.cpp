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
                    q.push({dis[newx][newy], {newx, newy}});
                    vis[newx][newy] = 1;
                }
            }
        }

        if(dis[n-1][m-1] == 1e9)  return -1;
        return dis[n-1][m-1] + 1;
    }
};



// same approach with cleaner code
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if (n == 1) return 1; // single cell [0][0] is both start and target

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // mark visited in-place

        int steps = 1;

        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();

                if (x == n - 1 && y == n - 1) return steps;

                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1; // mark visited immediately on push
                        q.push({nx, ny});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};


