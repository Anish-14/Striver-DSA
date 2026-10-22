#include<iostream>
#include "../LL.h"
using namespace std;

// Pair Sum in Sorted Doubly Linked List
// https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

class Solution {
  public:
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        vector<vector<int>> ans;
        Node* tail = head;
        
        while(tail->next != NULL){
            tail = tail->next;
        }
        
        // two pointer
        while(head != tail){
            int sum = head->data + tail->data;
            if(sum == target){
                ans.push_back({head->data, tail->data});
                head = head->next;
                if(head == tail)    break;
                tail = tail->prev;
            }
            else if(sum < target){
                head = head->next;
            }
            else{
                tail = tail->prev;
            }
        }
        
        return ans;
    }
};