#include<iostream>
#include "../LL.h"          
using namespace std;

// Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

class Solution {
public:
    int solve(ListNode* head, int n) {
        if (!head) return 0;

        int cnt = solve(head->next, n);

        // When cnt equals n, current node is immediately before the target node
        if (cnt == n) {
            ListNode* toDelete = head->next;
            head->next = head->next->next;
            delete toDelete; 
        }

        return 1 + cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalFromEnd = solve(head, n);

        // If total nodes counted equals n, the head itself is the N-th node from end
        if (totalFromEnd == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        return head;
    }
};