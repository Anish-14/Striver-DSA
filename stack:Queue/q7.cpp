#include<iostream>
#include<vector>
using namespace std;

// Previous Smaller Element
// https://www.geeksforgeeks.org/problems/previous-smaller-element/1

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i = 0; i<n; i++){
            int currAns = -1;
            while(!st.empty()){
                int topAns = st.top();
                if(topAns < arr[i]){
                    currAns = topAns;
                    break;
                }
                else{
                    st.pop();
                }
            }
            ans[i] = currAns;
            st.push(arr[i]);
        }
        
        return ans;
    }
};
