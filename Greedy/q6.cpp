#include<iostream>
using namespace std;

// good problem
// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
// job sequencing problem

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // solve it using minHeap
        int n = deadline.size();
        
        // sor the data in increasing order of deadline
        vector<pair<int,int>> data;
        for(int i = 0; i<n; i++){
            data.push_back({deadline[i], profit[i]});
        }
        
        sort(data.begin(), data.end());
        
        // create a minHeap which will store the profit and the min profit
        // will always be accessible so that if we want to include the one
        // greater than this then we can do that.
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // we will process the data deadline wise, when we have a deadline 
        // that is empty to fill then the if block get executed and a profit
        // is added, if the deadline is already occupied then we only update
        // the profit.
        for(int i = 0; i<n; i++){
            if(data[i].first > minHeap.size()){
                minHeap.push(data[i].second);
            }
            else if(!minHeap.empty() && data[i].second > minHeap.top()){
                minHeap.pop();
                minHeap.push(data[i].second);
            }
        }
        
        vector<int> ans = {0,0};
        
        while(!minHeap.empty()){
            ans[0]++;
            ans[1] += minHeap.top();
            minHeap.pop();
        }
        
        return ans;
    }
};




