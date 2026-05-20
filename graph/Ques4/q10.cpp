#include<iostream>
#include<vector>
using namespace std;

// Number of Operations to Make Network Connected
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/


class Solution {
public:
    vector<int> parent, rank;
    int getParent(int a, vector<int> &parent){
        if(parent[a] == a)  return a;
        return parent[a] = getParent(parent[a], parent);
    }
    void unionByRank(int a, int b, vector<int> &parent, vector<int> &rank){
        int pa = getParent(a, parent);
        int pb = getParent(b, parent);

        if(pa == pb)    return;

        if(rank[pa] < rank[pb]){
            parent[pa] = pb;
        }
        else if(rank[pb] < rank[pa]){
            parent[pb] = pa;
        }
        else{
            parent[pb] = pa;
            rank[pa]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // if the number of edges is less than n-1 then it is not possible to connect
        // all the nodes in the graph
        if(connections.size() < n-1){
            return -1;
        }

        // if it is possible to connect them all then the min number of ways is just
        // the number of components - 1 as we'll add every component with each other
        // with a node that is extra

        parent.resize(n);
        rank.resize(n, 1);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        for(int i = 0; i<connections.size(); i++){
            int a = connections[i][0];
            int b = connections[i][1];
            unionByRank(a, b, parent, rank);
        }

        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(getParent(i, parent) == i){
                cnt++;
            }
        }

        return cnt - 1;
    }
};


