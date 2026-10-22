#include<iostream> 
using namespace std;

// Pascal's triangle
// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i = 1; i<=numRows; i++){
            vector<int> temp(i, 1);
            for(int index = 1; index < i-1; index++){
                temp[index] = ans[i-2][index] + ans[i-2][index-1];      // here i-2 means the row just above us
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};

