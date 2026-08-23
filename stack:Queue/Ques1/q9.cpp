#include<iostream>
#include<vector>
using namespace std;

// Sum of Subarray Minimums
// https://leetcode.com/problems/sum-of-subarray-minimums/description/

class Solution {
public:
    vector<int> getNse(vector<int> &arr){
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return pse;
    }

    vector<int> getPsee(vector<int> &arr){
        int n = arr.size();
        vector<int> nsee(n);
        stack<int> st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            nsee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return nsee;
    }

    int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = getNse(arr);
        vector<int> psee = getPsee(arr);

        // for an element we'll see the nse and the psee(previous smaller or equal element)
        // we used psee here instead of pse to handle edge cases where we might get duplicate numbers
        // and the answer will be the multiplication of those number 
        // for sum we'll multiply it by arr[i]

        int ans = 0;
        for(int i = 0; i<n; i++){
            int previous = i - psee[i];
            int next = nse[i] - i;

            ans = (ans + (1LL*previous*next*arr[i])%MOD ) % MOD;
        }

        return ans;
    }
};




