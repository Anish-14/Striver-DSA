#include<iostream>
using namespace std;

// candy
// https://leetcode.com/problems/candy/description/

class Solution {
public:
    int candy(vector<int>& ratings) {
        // double pass greedy
        int n = ratings.size();
        vector<int> candies(n,1);

        // left se sum karo by height
        for(int i = 1; i<n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        // now we have to see the right height also
        int cnt = 0;
        for(int i = n-1; i>0; i--){
            if(ratings[i-1] > ratings[i]){
                candies[i-1] = max(candies[i] + 1, candies[i-1]);
            }
            cnt += candies[i-1];
        }

        return cnt + candies[n-1];
    }
};



// Optimal one with O(1) space
// slope method
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1, i = 1;

        while(i<n){
            // check for flat slope, if flat then give them one candy
            if(ratings[i] == ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            // for increasing slope, increase the candies and add them
            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            // for down slope we can do the same in reversed order as we just have to return the sum
            // and we don't have to worry about the order
            int down = 1;
            while(i<n && ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }
            
            // if this bottom has a value greater than peak then peak has to cover the delta for that
            if(down > peak){
                sum += down-peak;
            }
        }

        return sum; 
    }
};
