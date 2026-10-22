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

// another one
class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1){
            return 1;
        }

        int sum = 0;
        for(int i = 1; i<=n; i++){
            sum += numTrees(i-1)*numTrees(n-i);     // if i is root then left half will have i-1 nodes and right half n-i nodes
        }                                           // so the answer is multiplication of their number of trees

        return sum;
    }
};



