#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Most Stones Removed with Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

class Solution {
public:
    int getParent(int a, vector<int> &parent){
        if(parent[a] == a)  return a;
        return parent[a] = getParent(parent[a], parent);
    }

    void unionByRank(int a, int b, vector<int> &parent, vector<int> &rank){
        int para = getParent(a, parent);
        int parb = getParent(b, parent);

        if(para == parb)    return ;

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

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(2*1e4 + 2);
        vector<int> rank(2*1e4 + 2, 1);
        
        for(int i = 0; i<2*1e4+2; i++){
            parent[i] = i;
        }

        // we're treating each row and col as a different node and connecting them via
        // DSU, no. of parents are the one whom we can't remove, hence answer is n-cnt
        unordered_map<int,int> NodeList;
        for(auto it : stones){
            if(getParent(it[0], parent) != getParent(it[1] + 1e4 + 1, parent)){
                unionByRank(it[0], it[1] + 1e4 + 1, parent, rank);
                NodeList[it[0]] = 1;
                NodeList[it[1] + 1e4 + 1] = 1;
            }
        }

        int cnt = 0;
        for(auto it : NodeList){
            if(getParent(it.first, parent) == it.first){
                cnt++;
            }
        }

        return n - cnt;
    }
};