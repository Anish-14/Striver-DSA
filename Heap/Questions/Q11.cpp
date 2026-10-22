#include<iostream>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;

// smallest range from k sorted lists(sorted). 
// https://www.naukri.com/code360/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


// Approach 1: this approach is quite good to just know it, do watch the video to understand it better.

// take the first element of each k Linked list and make the first range by mini and maxi of those elements.
// we can't decrease the maxi here as after decreasing it the elements of that list won't be a part of it.
// but we can decrease the range, so we take the next element of the linked list where currently mini is present.
// and make many ranges an compare it to the smallest one, we'll keep track of smallest one throughout.
// saare pairs of range store karte jaao and last me minimum difference wala return kar dena
// ye sab every element in every LL ke liye karo, jaise hi koi array khaali ho gya then break. 



// Approach 2:
// implement the approach 1 by heap to save space and time complexities.

class node{
public:
    int data;
    int row;
    int col; 

    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node*a , node* b){
        return a->data > b->data;
    }
};


int kSorted(vector<vector<int>> &a, int k, int n) {
    
    // creating a min heap consisting nodes.
    priority_queue< node* , vector<node*>, compare > minHeap;
    int maxi = INT_MIN, mini = INT_MAX;

    // inserting first element of each LL in the minHeap.
    for(int i = 0; i<k; i++){
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0) );
    }

    // stores our range's start and end values.
    int start = mini, end = maxi;

    while(!minHeap.empty()){
        node* top = minHeap.top();
        minHeap.pop();

        // heap ke top ka data hi mini hoga, although we have it for first occurence but
        // it works for general occurence.
        mini = top->data;

        // ans updation, agar range chhoti mil gyi then update the smallest range.
        if(maxi - mini  <  end - start){
            start = mini;
            end = maxi;
        }

        // agar agla element hai us list me to heap me daal do.
        if(top->col + 1  < n){
            maxi = max(maxi , a[top->row][top->col + 1]);
            minHeap.push(new node( (a[top->row][top->col + 1]), top->row, top->col + 1) );
        }
        else{
            // ek LL ke empty hote hi hume bahr nikal jaana hai.
            break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
        }

    }

    // returning the value as asked by the platform.
    return (end - start + 1);
}



