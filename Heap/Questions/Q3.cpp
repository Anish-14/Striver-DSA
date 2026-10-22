#include<iostream>
#include<stack>
using namespace std;

// find kth smallest element in an array.

// Approach 1:
// sort the array and return the k-1 index value. TC : O(n*logn) 

// Approach 2:
// Make max heap of first k elements, then compare all other elements to the top element of heap
// if the value of the element is smaller than the root then pop it and push the smaller element, 
// do this for all elements from k to n-1 index.
// now heap.top() has your kth smallest element.
// TC : O(n*logk)   where n is the number of element in the array.

// each pq.push() takes "logk" time as inserting an element in heap takes that time and the 
// loop runs for k times
// then in worst case the other loop runs for all the element and for all the elements insertion happens
// thus making overall TC to be O(n*logk).

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function

    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> pq;             // made a max heap of first k elements.
        for(int i = l; i<k; i++){
            pq.push(arr[i]);
        }
        
        for(int i = k; i<=r; i++){          // k se last tak ko compare kar rhe hai, we want the 
            if(arr[i] < pq.top()){          // smallest elements to be in heap.
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        // as heap me k smallest elements from the array aa chuke hai, top of it surely 
        // contains the kth smallest elment as it is largest one.
        return pq.top();
    }
};