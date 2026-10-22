#include<iostream>
using namespace std;

// Rat in A Maze
// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:   
    bool isSafe(vector<vector<int>> &maze, int x, int y){
        int n = maze.size();
        if(x >= 0 && x < n && y >= 0 && y < n){
            return true;
        }
        
        return false;
    }
    void solve(vector<vector<int>> &maze, vector<vector<int>> &vis, 
    vector<string> &ans, string s, int row, int col, int n){
        // base case
        
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        
        // Down
        int x = row + 1;
        int y = col;
        
        if(isSafe(maze, x, y) && maze[x][y] == 1 && !vis[x][y]){
            vis[x][y] = 1;
            solve(maze, vis, ans, s + 'D', x, y, n);
            vis[x][y] = 0;
        }
        
        // Left
        x = row;
        y = col - 1;
        
        if(isSafe(maze, x, y) && maze[x][y] == 1 && !vis[x][y]){
            vis[x][y] = 1;
            solve(maze, vis, ans, s + 'L', x, y, n);
            vis[x][y] = 0;
        }
        
        // Right
        x = row;
        y = col + 1;
        
        if(isSafe(maze, x, y) && maze[x][y] == 1 && !vis[x][y]){
            vis[x][y] = 1;
            solve(maze, vis, ans, s + 'R', x, y, n);
            vis[x][y] = 0;
        }
        
        // Up
        x = row - 1;
        y = col;
        
        if(isSafe(maze, x, y) && maze[x][y] == 1 && !vis[x][y]){
            vis[x][y] = 1;
            solve(maze, vis, ans, s + 'U', x, y, n);
            vis[x][y] = 0;
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        if(maze[0][0] == 0){
            return ans;
        }
        solve(maze, visited, ans, "", 0, 0, n);
        
        return ans;
    }
};
