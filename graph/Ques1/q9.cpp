#include<iostream>
using namespace std;

// Number of Enclaves
// https://leetcode.com/problems/number-of-enclaves/description/

// let's solve it with bfs
// Appraoch --> 
// traverse bfs wise the boundary and whichever remains untouched, return that.
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));      // will work as a visited matrix
        queue<pair<int,int>> q;

        // first row
        for(int j = 0; j<m; j++){
            if(grid[0][j] == 1){
                vis[0][j] = 1;
                q.push({0, j});
            }
        }
        // last row
        for(int j = 0; j<m; j++){
            if(grid[n-1][j] == 1){
                vis[n-1][j] = 1;
                q.push({n-1, j});
            }
        }
        // first col
        for(int i = 1; i<n-1; i++){
            if(grid[i][0] == 1){
                vis[i][0] = 1;
                q.push({i, 0});
            }
        }
        // last col
        for(int i = 1; i<n-1; i++){
            if(grid[i][m-1] == 1){
                vis[i][m-1] = 1;
                q.push({i, m-1});
            }
        }

        // now apply bfs traversal
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, -1, 0, 1};

            for(int l = 0; l<4; l++){
                int nr = r + dx[l];
                int nc = c + dy[l];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }

        // now extract the ans from vis and grid matrix
        // we want the ones which are not visited

        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }

        return ans;
    }
};