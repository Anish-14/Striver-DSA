// Combination Sum
// https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    int n ;
    void getSum(vector<int> &candidates, int index, int target, vector<int> temp, vector<vector<int>> &ans){
        // base case
        if(target == 0){    // save answer and go back
            ans.push_back(temp);
            return;
        }
        if(index >= n || target <= 1){
            return;
        }

        // take
        temp.push_back(candidates[index]);
        getSum(candidates, index, target-candidates[index], temp, ans);
        temp.pop_back();

        // notTake
        getSum(candidates, index+1, target, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;

        getSum(candidates, 0, target, temp, ans);

        return ans;
    }
};