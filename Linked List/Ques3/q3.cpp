#include<iostream>
#include "../LL.h"
using namespace std;

// Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // whether there are k nodes present down the line or not
        ListNode* temp = head;
        for(int i = 0; i<k; i++){
            if(temp == NULL){
                return head;
            }
            temp = temp->next;
        }

        // we will call the recursive function 
        ListNode* nextHead = reverseKGroup(temp, k);

        // I will reverse the present call and merge it with one that is returning 
        // reverse
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        for(int i = 0; i<k; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // connect the current section to one who's ahead of it
        head->next = nextHead;

        // prev --> what I need to return to the earlier recursive call
        return prev;
    }
};
