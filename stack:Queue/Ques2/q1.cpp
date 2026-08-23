#include<iostream>
#include<vector>
using namespace std;

// Asteroid Collision
// https://leetcode.com/problems/asteroid-collision/description/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;

        for(int i = 0; i<n; i++){
            int num = asteroids[i];
            if(num > 0){
                ans.push_back(num);
            }
            else{
                bool toPush = 1;
                while(ans.size() > 0 && ans.back() > 0){
                    if(abs(num) > ans.back()){
                        ans.pop_back();
                    }
                    else{
                        // we'll not push it and leave it here only
                        if(abs(num) == ans.back()){
                            ans.pop_back();
                        }
                        toPush = 0;
                        break;
                    }
                }
                if(toPush){
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};