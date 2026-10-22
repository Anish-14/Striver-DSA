#include<iostream>
#include "../LL.h"
using namespace std;

// Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* next = head->next;

        while(next != NULL){
            if(next->val != temp->val){
                prev = temp;
                temp = next;
                next = next->next;
            }
            else{
                while(next->next != NULL && next->next->val == next->val){
                    next = next->next;
                }

                if(prev != NULL){
                    prev->next = next->next;
                }
                else{
                    head = next->next;
                }
                
                temp = next->next;
                next->next = NULL;
                if(temp){
                    next = temp->next;
                }
                else{
                    next = NULL;
                }
            }
        }

        return head;
    }
};
