#include<iostream>
using namespace std;

// Koko Eating Bananas
// https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    long long countTime(vector<int> &piles, int n, int mid){
        long long  cnt = 0;
        for(int i = 0; i<n; i++){
            long long temp = (piles[i]+mid-1)/mid;
            cnt += temp;
        }

        return cnt;
    }
    int getMax(vector<int> &piles, int n){
        int maxi = piles[0];
        for(int i = 1; i<n; i++){
            maxi = max(maxi, piles[i]);
        }

        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = getMax(piles, n);
        int s = 1, e = maxi;

        while(s <= e){
            int mid = s + (e-s)/2;

            long long cnt = countTime(piles, n, mid);
            if(cnt > h){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return s;
    }
};