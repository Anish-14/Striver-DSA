#include<iostream>
#include "../LL.h"
using namespace std;

// Linked List Cycle II
// starting point of the cycle in LL
// https://leetcode.com/problems/linked-list-cycle-ii/description/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            if(slow == fast){
                break;
            }
        }

        if(fast == NULL){
            return NULL;
        }

        ListNode* temp = head;
        // continue with slow

        while(temp != slow){
            temp = temp->next;
            slow = slow->next;
        }

        return temp;
    }
};