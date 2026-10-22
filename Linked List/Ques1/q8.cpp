#include<iostream>
#include "../LL.h"          
using namespace std;

// LL is pallindrome or not
// https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* prevSlow = NULL;
        ListNode* fast = head;

        while(fast != NULL){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
        }

        // slow is at middle node
        ListNode* curr = slow;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        prevSlow->next = prev;

        // cout<<prevSlow->val<<endl;
        // cout<<prev->val<<endl;

        // prev --> Head of the later half of the LL
        while(prev != NULL){
            if(prev->val != head->val){
                return false;
            }
            prev = prev->next;
            head = head->next;
        }

        return true;
    }
};