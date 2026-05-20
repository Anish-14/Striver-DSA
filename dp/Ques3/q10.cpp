#include<iostream>
using namespace std;

// Shortest Common Supersequence 
// https://leetcode.com/problems/shortest-common-supersequence/description/


// for the length of common supersequence --> len(s1) + len(s2) - LCS(s1, s2)

// printing the string --> 

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // let's build the LCS dp first 
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        // now we will make our supersequence from this dp matrix
        // as we've to take the common characters only once and the remaining one a single time
        // we'll start from the dp[n][m] and see if the current characters of both strings match
        // if they match then they've come from diagonal and if not then they've come from either
        // up or left

        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){     // matched! so I only need to take it once and move to upper left diagonal
                ans += str1[i-1];
                i--; j--;
            }
            else{
                if(dp[i-1][j] >= dp[i][j-1]){   // up is greater
                    ans += str1[i-1];
                    i--;
                }
                else{   // left is greater
                    ans += str2[j-1];
                    j--;
                }
            }
        }
        while(i > 0){
            ans += str1[i-1];
            i--;
        }
        while(j > 0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};







