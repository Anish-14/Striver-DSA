#include<iostream>
using namespace std;

// K-th Permutation Sequence 
// https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        // we need (n-1)! and we want to store the number in temp
        vector<int> temp;
        int fact = 1;

        for(int i = 1; i<n; i++){
            fact = fact * i;
            temp.push_back(i);
        }

        temp.push_back(n);

        k = k-1;    // we have to decrease it by one as we're accessing everything index wise

        string ans = "";       // initialize the answer with empty string
        while(true){
            ans = ans + to_string(temp[k/fact]);    // the number at k/fact index will be at start
            temp.erase(temp.begin() + k/fact);                     // now we will erase this number from the array
            if(temp.size() == 0){
                break;
            }

            k = k % fact;
            fact = fact/temp.size();
        }

        return ans;
    }
};