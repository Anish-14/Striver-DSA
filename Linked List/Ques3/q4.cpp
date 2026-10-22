#include<iostream>
#include "../LL.h"
using namespace std;

// Rotate List
// https://leetcode.com/problems/rotate-list/description/

class Solution {
public:
    int getLen(ListNode* head){
        int cnt = 0;
        while(head != NULL){
            head = head->next;
            cnt++;
        }

        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }
        int n = getLen(head);

        k = k % n;
        if(k == 0){
            return head;
        }

        // loop over the LL to get to the n-k th node
        ListNode* temp = head;
        for(int i = 0; i<n-k-1; i++){
            temp = temp->next;
        }

        ListNode* newHead = temp->next;     // save the head to return

        // let's connect the last one to the first one
        ListNode* curr = temp;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = head;

        temp->next = NULL;

        return newHead;
    }
};
