#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Making A Large Island
// https://leetcode.com/problems/making-a-large-island/description/

class Solution {
public:
    int getParent(int a, vector<int> &parent){
        if(parent[a] == a)  return a;
        return parent[a] = getParent(parent[a], parent);
    }

    void unionBySize(int a, int b, vector<int> &parent, vector<int> &size){
        int para = getParent(a, parent);
        int parb = getParent(b, parent);

        if(para == parb)    return ;

        if(size[para] < size[parb]){
            parent[para] = parb;
            size[parb] += size[para];
        }
        else{
            parent[parb] = para;
            size[para] += size[parb];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        // first create the graph and count the components
        // then for all zeros try converting them to one and answer 
        // will be the ones which are getting connected to the right, left, up and down
        // we have to implemnet union by size here
        int n = grid.size();
        vector<int> parent(n*n);
        vector<int> size(n*n, 1);

        for(int i = 0; i<n*n; i++){
            parent[i] = i;
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};

        // first step --> connect all the nodes adj to each other
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    int currNode = i*n + j;
                    for(int num = 0; num < 4; num++){
                        int newx = i + dx[num];
                        int newy = j + dy[num];
                        if(newx >= 0 && newy < n && newy >=0 && newx < n && grid[newx][newy] == 1){
                            int adjNode = newx*n + newy;
                            unionBySize(currNode, adjNode, parent, size);
                        }
                    }
                }
            }
        }

        // step 2 --> convert each 0 to 1 and check for answer
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1) continue;
                set<int> components;
                for(int num = 0; num<4; num++){
                    int newx = i + dx[num];
                    int newy = j + dy[num];
                    if(newx >= 0 && newx < n && newy >= 0 && newy < n && grid[newx][newy] == 1){
                        int currNode = i*n + j;
                        int adjNode = newx*n + newy;
                        components.insert(getParent(adjNode, parent));
                    }
                }
                int curr = 0;
                for(auto it : components){
                    curr += size[it];
                }
                ans = max(ans, curr+1);
            }
        }

        // edge case --> what if all entries are zero
        for(int i = 0; i<n*n; i++){
            ans = max(ans, size[i]);
        }

        return ans;
    }
};

