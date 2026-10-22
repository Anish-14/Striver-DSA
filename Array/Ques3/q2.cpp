#include<iostream>
using namespace std;

// Merge Intervals
// https://leetcode.com/problems/merge-intervals/description/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        pair<int,int> prev = make_pair(intervals[0][0], intervals[0][1]);

        for(int i = 1; i<n; i++){
            pair<int,int> curr = make_pair(intervals[i][0], intervals[i][1]);

            // merge pairs
            if(prev.second >= curr.first){
                prev.second = max(prev.second, curr.second);
            }   
            else{   // save ans
                vector<int> temp;
                temp.push_back(prev.first);
                temp.push_back(prev.second);

                prev = curr;
                ans.push_back(temp);
                temp.clear();
            }
        }
        vector<int> temp;
        temp.push_back(prev.first);
        temp.push_back(prev.second);
        ans.push_back(temp);
        temp.clear();

        return ans;
    }
};


