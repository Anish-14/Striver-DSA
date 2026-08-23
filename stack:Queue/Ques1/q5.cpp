#include<iostream>
#include<vector>
using namespace std;

// min stack implementation --> stack which can also give the smallest element so far

class MinStack {
private: 
    vector<vector<int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minVal = getMin();
        if(st.empty() || minVal > val){
            minVal = val;
        }
        st.push_back({val, minVal});
    }
    
    void pop() {
        if(!st.empty()){
            st.pop_back();
        }
    }
    
    int top() {
        return st.empty() ? -1 : st.back()[0];
    }
    
    int getMin() {
        return st.empty() ? -1 : st.back()[1];
    }
};



