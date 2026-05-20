#include<iostream>
using namespace std;

// Rotten Oranges
// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        queue<pair<pair<int,int>, int>> q;     // row, col, time stamp
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int currTime = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                // explore all the neighbours
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1){
                    ans = max(ans, currTime + 1);
                    q.push({{newr, newc}, currTime + 1});
                    grid[newr][newc] = 2;
                }
            }

        }

        // If it is not possible to rot all the oranges then return -1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;
    }
};
