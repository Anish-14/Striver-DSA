#include<iostream>
using namespace std;

// Floyd Warshall Algorithm
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

// check paths i->k and k->j and update the path i->j if required
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8)   continue;  // if k is unreaachable from i or j is unreachable from k, then skip
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
    }
};
