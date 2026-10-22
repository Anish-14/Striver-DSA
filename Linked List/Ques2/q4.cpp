#include<iostream>
#include "../LL.h"
using namespace std;

// Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/description/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // slow fast pointer
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};