#include<iostream>
using namespace std;

// Number of Islands
// https://leetcode.com/problems/number-of-islands/description/


class Solution {
public:
    int n, m;
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> & grid){
        vis[row][col] = 1;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        for(int k = 0; k<4; k++){
            int newr = row + dx[k];
            int newc = col + dy[k];

            if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == '1' && !vis[newr][newc]){
                dfs(newr, newc, vis, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // we'll use dfs
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    dfs(i, j, vis, grid);
                }
            }
        }

        return ans;
    }
};
