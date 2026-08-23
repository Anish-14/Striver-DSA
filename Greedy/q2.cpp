#include<iostream>
using namespace std;

// https://leetcode.com/problems/lemonade-change/
// Lemonade Change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;

        for(int i = 0; i<n; i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five <= 0){
                    return false;
                }
                ten++;
                five--;
            }
            else{
                if(ten >= 1 && five >= 1){
                    ten--;
                    five--;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
};