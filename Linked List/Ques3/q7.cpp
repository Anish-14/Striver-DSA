#include<iostream>
#include "../LL.h"
using namespace std;

// Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/description/

class Solution {
public:
    // this is the magical class
    class compare{
        public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;         // here this tells that a node with greater value should go down therefore this creates a minHeap
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for(int i = 0; i<lists.size(); i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;

        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();

            if(temp->next != NULL){
                minHeap.push(temp->next);
            }

            ans->next = temp;
            ans = ans->next;
        }

        return dummy->next;
    }
};


