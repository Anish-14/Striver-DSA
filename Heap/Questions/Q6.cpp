#include<iostream>
#include<stack>
using namespace std;

// minimum cost of ropes

// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths.
// The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 


// Aproach:
// we'll make a min heap and put all the values of array in that heap.
// we'll take two smallest element and add them to get our cost and add the new length of rope in the heap.
// we'll do this till heap has 1 element left.
// we'll store our cost in "ans" variable and return that variable.

// TC : O(nlogn)        // pop && push is in logn time
// SC : O(n)

long long minCost(long long arr[], long long n) {
    // initializing a min heap
    priority_queue< long long, vector<long long>, greater<long long> > pq;
    
    // copying the elements of array in min heap.
    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
    }
    
    long long ans = 0;
    
    while(pq.size() > 1){
        // accessing two smallest elements.
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        
        // updating our ans which stores cost.
        long long sum = a+b;        // sum is the new length of rope
        ans += sum;
        
        // add new length of rope to the heap.
        pq.push(sum);
    }
    
    return ans;
}

