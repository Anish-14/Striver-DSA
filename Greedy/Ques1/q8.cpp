#include<iostream>
using namespace std;

// https://leetcode.com/problems/non-overlapping-intervals/
// Non-overlapping Intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;

        // sort in increasing order
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int prev_end = intervals[0][1];

        // in res++ in our mind we are deleting the current interval 
        // make the number line to understand it
        for (int i = 1; i < intervals.size(); i++) {
            if (prev_end > intervals[i][0]) {
                res++;
            } else {
                prev_end = intervals[i][1];
            }
        }

        return res;        
    }
};


