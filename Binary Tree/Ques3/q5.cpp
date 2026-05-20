#include<iostream>
using namespace std;
#include "syntax.h"

// Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/description/

class Solution {
public:
    int numTrees(int n) {
        vector<int> uniqueTrees(n+1, 0);
        uniqueTrees[0] = 1;
        uniqueTrees[1] = 1;

        for(int nodes = 2; nodes <= n; nodes++){
            for(int root = 1; root<=nodes; root++){
                uniqueTrees[nodes] += uniqueTrees[root-1] * uniqueTrees[nodes-root];
            }
        }
        
        return uniqueTrees[n];
    }
};


