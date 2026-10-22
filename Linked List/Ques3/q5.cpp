#include<iostream>
#include "../LL.h"
using namespace std;

// Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/description/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }

        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* head = new ListNode(-1);      // dummy 
        ListNode* ans = head;                   // return ans->next;

        while(first != NULL && second != NULL){
            if(first->val <= second->val){
                head->next = first;
                first = first->next;
            }
            else{
                head->next = second;
                second = second->next;
            }
            head = head->next;
        }
        while(first != NULL){
            head->next = first;
            first = first->next;
            head = head->next;
        }
        while(second != NULL){
            head->next = second;
            second = second->next;
            head = head->next;
        }

        return ans->next;
    }
};

