#include<iostream>
#include "../LL.h"          
using namespace std;

// Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;

        ListNode* currOdd = odd;
        ListNode* currEven = even;
        ListNode* prev = odd;
        while(currOdd){
            prev = currOdd;
            if(currEven){
                currOdd->next = currEven->next;
                currOdd = currOdd->next;
                if(currOdd){
                    currEven->next = currOdd->next;
                    currEven = currEven->next;
                }
            }
            else{
                break;
            }
        }

        prev->next = even;

        return odd;
    }
};
