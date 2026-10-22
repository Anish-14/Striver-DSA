#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


// merge k sorted arrays.
// Good Question.
// https://www.naukri.com/code360/problems/merge-k-sorted-arrays_975379?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


// Approach 1:
// we'll put every array in our ans array and then sort our ans array and return it.

// Approach 2:
// using min Heap

class node{
 public:
    int data;
    int row;
    int col;

    node(int data, int row, int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

// ye class hai jisse hum min heap me compare kar rhe hai.
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // understand how we implemented min heap.
    priority_queue< node*, vector<node*>, compare > minHeap;

    // step 1: saare k arrays ke first element ko daal do.
    // size 0 nhi hoga kisi array ka ye diya hai and remember the arrays given are sorted
    for(int i = 0; i<k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // step 2: top element ke data ko apne ans me daal rhe hai.
    // and if us array ka agla element hai then usko push kar rhe hai.
    while(!minHeap.empty()){
        node* tmp = minHeap.top();

        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->row;
        int j = tmp->col;

        // kya is array me agla element available hai, ye check kar rhe hai.
        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1] , i , j+1);
            minHeap.push(next);
        }
    }

    return ans;
}











