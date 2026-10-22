#include<iostream>
#include<stack>
using namespace std;

// Heap Sort

// algo
// root node is largest so usko swap kar do so that vo last me chala jaaye, size ko ghata do taaki that largest value lock ho jaaye.
// jo node 1st node per hai usko sahi jagah le jaao
// n.logn is time complexity of hapsort algo.
void heapsort(int arr[], int n){
    int size = n;

    while(size > 1){
        // step 1: swap
        swap(arr[size], arr[1]);
        size--;

        // step 2: call heapify
        heapify(arr, size , 1);
    }
}


