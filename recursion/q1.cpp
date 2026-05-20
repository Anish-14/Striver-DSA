// Check if there exists a subsequence with sum K
// https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1

class Solution {
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k){
        // Code here
        vector<bool> dp(k+1, 0);     // represents that this sum can be form in the array or not taking subsequences
        dp[0] = 1;                  // zero sum is possible for any array
        
        for(int i = 0; i<n; i++){
            int val = arr[i];
            for(int j = k; j>=val; j--){
                if(dp[j-val]){          // if "j-val" sum exist then "j" sum also exist because our sequence is giving us 
                    dp[j] = 1;          // sum of j from it.
                }
            }
        }
        
        return dp[k];           // at last we return the sum for k if exists.
    }
};