#include<iostream>
using namespace std;

// Find the City With the Smallest Number of Neighbors at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, 1e8));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j){
                    dis[i][j] = 0;
                }
            }
        }

        for(auto it : edges){
            dis[it[0]][it[1]] = it[2];
            dis[it[1]][it[0]] = it[2];
        }

        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){ 
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int node = -1;
        int ans = 1e8;
        for(int i = 0; i<n; i++){
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(i == j)  continue;
                if(dis[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= ans){
                ans = cnt;
                node = i;
            }
        } 

        return node;
    }
};


