#include<iostream>
using namespace std;

//  Longest Bitonic Sequence
//  https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688?leftPanelTabValue=PROBLEM


int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// make two dp vectors for increasing and decreasing length of LIS type
    // then figure something out
    if(arr.size() == 0){
        return 0;
    }

    vector<int> increase_dp(n, 1);
    vector<int> decrease_dp(n, 1);


    // let's build for increasing
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i] > arr[j] && 1 + increase_dp[j] > increase_dp[i]){
                increase_dp[i] = 1 + increase_dp[j];
            }
        }
    }

    // let's build for decreasing
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>i; j--){
            if(arr[i] > arr[j] && 1 + decrease_dp[j] > decrease_dp[i]){
                decrease_dp[i] = 1 + decrease_dp[j];
            }
        }
    }
    

    // now we'll figure out the answer
    // only increasing, only decreasing or bitonic
    int ans = 1;
    for(int i = 0; i<n; i++){
        int inc = increase_dp[i];
        int dec = decrease_dp[i];
        int bito = increase_dp[i] + decrease_dp[i] - 1;

        ans = max(ans, max(inc, max(dec, bito)));
    }

    return ans;
}





