#include<iostream>
using namespace std;

// Minimum Number of Days to Make m Bouquets
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

class Solution {
public:
    int cntFlower(vector<int> &bloomDay, int k, int mid){
        int n = bloomDay.size();
        int ans = 0, cnt = 0;
        for(int i = 0; i<=n; i++){
            if(i == n){
                ans += cnt/k;
                break;
            }

            if(mid >= bloomDay[i]){
                cnt++;
            }
            else{
                ans += cnt/k;
                cnt = 0;
            }
        }

        return ans;
    }
    int getMaxi(vector<int> &bloomDay){
        int maxi = -1;
        for(int i = 0; i<bloomDay.size(); i++){
            maxi = max(maxi, bloomDay[i]);
        }

        return maxi;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = getMaxi(bloomDay);
        int s = 1, e = maxi;

        while(s <= e){
            int mid = s + (e-s)/2;
            int cnt = cntFlower(bloomDay, k, mid);

            if(cnt < m){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        if(s > maxi)    return -1;
        return s;
    }
};


