#include<iostream>
using namespace std;

// Minimum Multiplications to reach End
// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0

class Solution {
  public:
    int mod = 1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        q.push({0, start});     // steps, node
        vector<int> dis(100000, 1e9);
        dis[start] = 0;
        
        if(start == end)    return 0;
        
        while(!q.empty()){
            int currStep = q.top().first;
            int node = q.top().second;
            q.pop();
            
            for(int i = 0; i<arr.size(); i++){
                int temp = (node%mod*arr[i]%mod) % mod;
                if(temp == end) return currStep + 1;
                if(currStep + 1 < dis[temp]){
                    dis[temp] = currStep + 1;
                    q.push({currStep+1, temp});
                }
            }
        }
        
        return -1;
    }
};



