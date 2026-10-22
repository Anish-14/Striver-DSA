#include<iostream>
using namespace std;

// Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets/description/

// I think I probably have done some extra in solving that, I think it can be solved 
// using two simple variables instead of map as well
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n <= 2)  return n;

        int left = 0, ans = 2;
        unordered_map<int,int> mp;
        mp[fruits[0]] = 0;
        mp[fruits[1]] = 1;

        int i = 2;
        for(; i<n; i++){
            if(mp.size() == 2 && mp.find(fruits[i]) == mp.end()){
                ans = max(ans, i-left);
                for(auto it : mp){
                    if(it.first != fruits[i-1]){
                        left = it.second+1;
                        mp.erase(it.first);
                        mp[fruits[i]] = i;
                        break;
                    }
                }
            }
            else{
                mp[fruits[i]] = i;
            }
        }
        ans = max(ans, i-left);

        return ans;
    }
};
