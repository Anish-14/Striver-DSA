#include<iostream>
#include<vector>
using namespace std;

// Online Stock Span
// https://leetcode.com/problems/online-stock-span/description/

class StockSpanner {
public:
    stack<pair<int,int>> st;        // price , ans
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        // we want to store in decreasing order in stack
        while(!st.empty()){
            auto p = st.top();
            if(p.first <= price){
                st.pop();
                ans += p.second;
            }
            else{
                break;
            }
        }

        st.push(make_pair(price, ans));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


