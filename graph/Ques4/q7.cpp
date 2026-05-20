#include<iostream>
#include<vector>
using namespace std;

// disjoint set implementation 
// Lec. 46 striver

class DisjointSet{
    vector<int> parent, rank, size;
     
    public:
    DisjointSet(int n){
        parent.resize(n+1);             // this will work for both one and zero based graph
        rank.resize(n+1, 0);
        size.resize(n+1, 0);
        for(int i = 0; i<=n ;i++){
            parent[i] = i;
        }
    }

    int getParent(int a){
        if(parent[a] == a)  return parent[a];
        return parent[a] = getParent(parent[a]);        // we're implementing path compression here
    }

    void unionByRank(int a, int b){
        int ulpA = getParent(a);   // ultimateParA
        int ulpB = getParent(b);   // ultimateparB

        if(ulpA == ulpB)    return;         // they both already are in same graph

        if(rank[ulpA] < rank[ulpB]){
            parent[ulpA] = ulpB;
        }
        else if(rank[ulpA] > rank[ulpB]){
            parent[ulpB] = ulpA;
        }
        else{   // both have same rank
            parent[ulpB] = ulpA;
            rank[ulpA]++;
        }
    }

    void unionBySize(int a, int b){
        int ulpA = getParent(a);   // ultimateParA
        int ulpB = getParent(b);   // ultimateparB

        if(ulpA == ulpB)    return;         // they both already are in same graph

        if(size[ulpA] < size[ulpB]){
            parent[ulpA] = ulpB;
            size[ulpB] += size[ulpA];
        }
        else{                               // this will suffice for both greater than and equal to case
            parent[ulpB] = ulpA;
            size[ulpA] += size[ulpB];
        }
    }
};


