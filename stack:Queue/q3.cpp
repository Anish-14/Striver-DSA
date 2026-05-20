#include<iostream>
#include<vector>
using namespace std;

// Implementing a stack using arrays
// 

class myStack{
public:
    vector<int> v;
    int size;
    int index = 0;

    myStack(int n){
        size = n;
        v.resize(n);
    }
    void push(int x){
        if(index >= size){
            cout<<"stack Overflow"<<endl;
            return;
        }
        v[index++] = x;
    }
    void pop(){
        if(index <= 0){
            cout<<"stack Underflow"<<endl;
            return;
        }
        index--;
    }
    int top(){
        if(index <= 0){
            cout<<"stack Underflow"<<endl;
            return -1;
        }
        return v[index-1];
    }
    bool isEmpty(){
        return index == 0;
    }
};
