#include<iostream>
using namespace std;

// Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/description/

// Approach --> 
// I will start with the "O" that is at the shore and then I will apply a traversal
// technique to find what "O" can't be converted into "X" and then I'll simply replace
// the rest "O" with "X".
class Solution {
public:
    int n, m;
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis){
        vis[i][j] = 1;

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        for(int k = 0; k<4; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && board[nr][nc] == 'O' && !vis[nr][nc]){
                dfs(nr, nc, board, vis);
            }
        }
        return ;
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
       
        // first row
        for(int j = 0; j<m; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
                    dfs(0, j, board, vis);
                }
        }
        // last row
        for(int j = 0; j<m; j++){
            if(board[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(n-1, j, board, vis);
            }
        }
        // first column
        for(int i = 1; i<n-1; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, board, vis);
            }
        }
        // last column
        for(int i = 1; i<n-1; i++){
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i, m-1, board, vis);
            }
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout<<vis[i][j]<<" ";
            }cout<<endl;
        }

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};



// Optimum approach --> Try to understand it this was the 100% result on leetcode

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        stack<pair<int,int>> st;

        auto pushIfO = [&](int x, int y) {
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O') {
                st.push({x, y});
                board[x][y] = '#'; 
            }
        };

        for (int i = 0; i < m; i++) {
            pushIfO(i, 0);
            pushIfO(i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            pushIfO(0, j);
            pushIfO(m - 1, j);
        }

        while (!st.empty()) {
            auto [x, y] = st.top(); st.pop();
            pushIfO(x - 1, y);
            pushIfO(x + 1, y);
            pushIfO(x, y - 1);
            pushIfO(x, y + 1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X'; 
                else if (board[i][j] == '#') board[i][j] = 'O'; 
            }
        }
    }
};

