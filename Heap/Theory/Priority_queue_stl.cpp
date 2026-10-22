#include<iostream>
#include<queue> 
using namespace std;

int main(){

    // this is stl implementation of Heaps.
    // If want to learn more inbuilt functions then go to any website and learn about it.

    // max heap
    priority_queue<int> maxheap;
    maxheap.push(4);
    maxheap.push(78);
    maxheap.push(9);
    maxheap.push(34);
    maxheap.push(41);

    cout<<"element at top is: "<<maxheap.top()<<endl;       // maximum element aana chahiye
    maxheap.pop();
    cout<<"element at top is: "<<maxheap.top()<<endl;       // pop() delete ki tarah kaam karta hai and root ko delete kar dega, so now top should change.
    cout<<"size of heap is: "<<maxheap.size()<<endl;
    if(maxheap.empty()){
        cout<<"this is empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }


    // min heap
    priority_queue<int, vector<int> , greater<int> > minheap;
    minheap.push(4);
    minheap.push(78);
    minheap.push(9);
    minheap.push(34);
    minheap.push(41);

    cout<<"element at top is: "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"element at top is: "<<minheap.top()<<endl;
    cout<<"size of heap is: "<<minheap.size()<<endl;
    if(minheap.empty()){
        cout<<"this is empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }

}