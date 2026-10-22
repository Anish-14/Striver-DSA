#include<iostream>
using namespace std;

// Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
public:
    priority_queue<int> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int> > rightMinHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // we're pushing the first element in leftMaxHeap
        if(leftMaxHeap.empty() || num <= leftMaxHeap.top()){
            leftMaxHeap.push(num);
        }
        else{
            rightMinHeap.push(num);
        }

        // balance the Heaps
        if(leftMaxHeap.size() > rightMinHeap.size() + 1){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
        }
        else if(rightMinHeap.size() > leftMaxHeap.size()){
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
        }
    }
    
    double findMedian() {
        if(leftMaxHeap.size() > rightMinHeap.size()){
            return leftMaxHeap.top();
        }
        else{
            return (leftMaxHeap.top() + rightMinHeap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */