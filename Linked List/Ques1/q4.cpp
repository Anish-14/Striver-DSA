#include<iostream>
#include "../LL.h"          
using namespace std;

// sort list
// https://leetcode.com/problems/sort-list/

// merge sort works best on LL
class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right){
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;

        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                ans->next = new ListNode(left->val);
                left = left->next;
            }
            else{
                ans->next = new ListNode(right->val);
                right = right->next;
            }
            ans = ans->next;
        }
        while(left != NULL){
            ans->next = new ListNode(left->val);
            left = left->next;
            ans = ans->next;
        }
        while(right != NULL){
            ans->next = new ListNode(right->val);
            right = right->next;
            ans = ans->next;
        }

        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        // Merge Sort
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;      // seperate the two LLs

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        ListNode* sortedLL = merge(left, right);

        return sortedLL;
    }
};



