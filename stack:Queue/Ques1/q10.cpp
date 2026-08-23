#include<iostream>
#include<vector>
using namespace std;

// Sum of Subarray Ranges
// https://leetcode.com/problems/sum-of-subarray-ranges/description/

// great question 
// we implemented largest subset sum and smallest subset here and simply subtracted them
class Solution {
public:
    int n;
    vector<int> getNlee(vector<int> &nums){
        vector<int> nlee(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            nlee[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nlee;
    }
    vector<int> getPle(vector<int> &nums){
        vector<int> ple(n);
        stack<int> st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }

            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ple;
    }
    long long getLarge(vector<int> &nums){
        vector<int> ple = getPle(nums);
        vector<int> nlee = getNlee(nums);
        
        long long ans = 0;
        for(int i = 0; i<n; i++){
            int left = i - ple[i];
            int right = nlee[i] - i;

            ans += (1LL * left*right*nums[i]);
        }

        return ans;
    }

    vector<int> getNsee(vector<int> &nums){
        vector<int> nsee(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            nsee[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nsee;
    }
    vector<int> getPse(vector<int> &nums){
        vector<int> pse(n);
        stack<int> st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }
    long long getSmall(vector<int> &nums){
        vector<int> pse = getPse(nums);
        vector<int> nsee = getNsee(nums);

        long long ans = 0;
        for(long long i = 0; i<n; i++){
            long long left = i-pse[i];
            long long right = nsee[i] - i;

            ans += (left*right*nums[i]);
        }

        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        // we will treat as the largest - smallest 
        n = nums.size();
        long long largest = getLarge(nums);
        long long smallest = getSmall(nums);

        return largest - smallest;   
    }
};
