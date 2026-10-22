#include<iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1
// N meetings in one room

class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();
        vector<pair<int,int>> finish;
        
        for(int i = 0; i<n; i++){
            finish.push_back({f[i], i});
        }
        
        sort(finish.begin(), finish.end());
        
        vector<int> ans;
        int prevEnd = -1;
        
        for(int i = 0; i<n; i++){
            int currStart = s[finish[i].second];
            if(currStart > prevEnd){
                ans.push_back(finish[i].second + 1);
                prevEnd = finish[i].first;
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};