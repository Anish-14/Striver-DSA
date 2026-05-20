#include<iostream>
#include<vector>
using namespace std;

// Number of Island - II
// https://www.geeksforgeeks.org/problems/number-of-islands/1

// User function Template for C++
class Solution {
  public:
  
    int getParent(int a, vector<int> &parent){
        if(parent[a] == a)  return a;
        return parent[a] = getParent(parent[a], parent);
    }
    
    void unionByRank(int a, int b, vector<int> &parent, vector<int> &rank){
        int para = getParent(a, parent);
        int parb = getParent(b, parent);
        
        if(para == parb)    return;
        
        if(rank[para] < rank[parb]){
            parent[para] = parb;    
        }
        else if(rank[parb] < rank[para]){
            parent[parb] = para;
        }
        else{
            parent[parb] = para;
            rank[para]++;
        }
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> parent(n*m);
        vector<int> rank(n*m, 1);
        
        for(int i = 0; i<n*m; i++){
            parent[i] = i;
        }
        
        vector<vector<int>> vis(n, vector<int>(m));
        
        int cnt = 0;    // no. of component
        vector<int> ans;
        
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            vector<int>dx = {-1, 0, 1, 0};
            vector<int>dy = {0, -1, 0, 1};
            
            for(int ind = 0; ind<4; ind++){
                int newr = row + dx[ind];
                int newc = col + dy[ind];
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc]){
                    int nodeNo = row*m + col;
                    int adjNodeNo = newr*m + newc;
                    if(getParent(nodeNo, parent) != getParent(adjNodeNo, parent)){
                        unionByRank(nodeNo, adjNodeNo, parent, rank);
                        cnt--;
                    }
                    
                }
            }
            ans.push_back(cnt);
            
        }
        
        return ans;
    }
};


