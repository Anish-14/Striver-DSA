#include<iostream>
#include<vector>
using namespace std;

// Implementing a queue using arrays


class myQueue{
private:
    vector<int> v;
    int curr;
    int start;
    int size ;

public:
    myQueue(int n){
        v.resize(n);
        curr = -1;
        start = -1;
        size = n;
    } 

    void push(int x){
        if((curr+1)%size == start){
            cout<<"Queue Overlow"<<endl;
            return;
        }

        // first element 
        if(start == -1){
            start = curr = 0;
        }
        else{
            curr = (curr+1)%size;
        }

        v[curr] = x;
    }

    void pop(){
        if(start == -1){
            cout<<"Queue Underflow"<<endl;
            return;
        }

        if(start == curr){
            start = curr = -1;
        }
        else{
            start = (start+1)%size;
        }
    }

    int top(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }

        return v[start];
    }

    bool isEmpty(){
        return start == -1;
    }
};




// Easier implementation using an extra variable size
class myQueue{
private:
    vector<int> v;
    int front, rear, size, count;

public:
    myQueue(int n){
        size = n;
        v.resize(n);
        front = 0;
        rear = -1;
        count = 0;
    }

    void push(int x){
        if(count == size){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        rear = (rear + 1) % size;
        v[rear] = x;
        count++;
    }

    void pop(){
        if(count == 0){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front = (front + 1) % size;
        count--;
    }

    int top(){
        if(count == 0){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        return v[front];
    }

    bool isEmpty(){
        return count == 0;
    }
};
