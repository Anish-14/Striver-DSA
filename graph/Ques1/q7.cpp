#include<iostream>
using namespace std;

// 01 Matrix
// https://leetcode.com/problems/01-matrix/description/


// BFS approach
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dis(n, vector<int>(m , -1));     // this will act both as dis as well as vis matrix
        queue<pair<int,int>> q;
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, -1, 0, 1};

            for(int i = 0; i<4; i++){
                int newr = row + dx[i];
                int newc = col + dy[i];
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && dis[newr][newc] == -1){
                    q.push({newr, newc});
                    dis[newr][newc] = dis[row][col] + 1;
                }
            }
        }

        return dis;
    }
};


