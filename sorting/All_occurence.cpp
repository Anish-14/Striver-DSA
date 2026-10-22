#include<iostream>
using namespace std;

// solve the following problem
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int index = s.find(part);
        while(index != string :: npos){
            s.erase(index, part.length());
            index = s.find(part);
        }

        return s;
    }
};

// this isn't the best solution, we can use stack to solve this problem