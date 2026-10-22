#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

// merge k sorted linked lists.
// https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

// Approach 1:
// make a array with all the data of the linked lists and sort it
// connect all the linked lists
// copy the values from array to the list

// Approach 2:
// Same approch as in Q9 for k sorted arrays.
class Node{
public:
    int data;
    Node* next;

    Node(int a){
        data = a;
        next = NULL;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node*b){
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*> &listArray){
    
    // creating a min Heap.
    priority_queue< Node*, vector< Node* >, compare > minHeap;

    // listArray contain the heads of the "k" linked lists.
    int k = listArray.size();

    if(k == 0){
        return NULL;
    }

    // copy first k nodes in heap;
    for(int i = 0; i<k; i++){

        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    // isi head ko return karna hai.
    Node* head = NULL;
    Node* tail = NULL;


    while(!minHeap.empty()){
        Node* top = minHeap.top();
        minHeap.pop();

        // first entry.
        if(head == NULL){
            head = top; 
            tail = top;

            if(top->next != NULL){
                minHeap.push(top->next);
            }
        }
        else{   // head NULL nhi hai to uske baad ki entries    
            tail->next = top;
            tail = top;     
            if(top->next != NULL){
                minHeap.push(top->next);
            }
        }
    }

    return head;
}

