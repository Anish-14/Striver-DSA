#include<iostream>
using namespace std;

// Maximum Points You Can Obtain from Cards
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // sliding window
        int n = cardPoints.size();
        int res = 0;

        for(int i = 0; i<k; i++){
            res += cardPoints[i];
        }

        int curr = res;
        for(int i = k-1; i>=0; i--){
            curr -= cardPoints[i];
            curr += cardPoints[n-k+i];

            res = max(res, curr);
        }

        return res;
    }
};

