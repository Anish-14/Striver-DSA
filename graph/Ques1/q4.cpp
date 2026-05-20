#include<iostream>
using namespace std;

// Flood Fill
// https://leetcode.com/problems/flood-fill/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // we should bfs here
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int startPixel = image[sr][sc];
        ans[sr][sc] = color;

        queue<pair<int,int>> q;     // row, col
        q.push({sr, sc});
        vis[sr][sc] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && image[newr][newc] == startPixel && !vis[newr][newc]){
                    ans[newr][newc] = color;
                    vis[newr][newc] = 1;
                    q.push({newr, newc});
                }
            }
        }

        return ans;
    }
};






