#include<iostream>
#include "../LL.h"          
using namespace std;

// Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/description/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        int carry = 0;

        while(l1 != NULL || l2 != NULL){
            int sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
            int ans = sum%10;
            carry = sum/10;

            dummy->next = new ListNode(ans);
            dummy = dummy->next;

            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
        }
        while(carry){
            dummy->next = new ListNode(carry%10);
            carry = carry/10;
        }
        
        return head->next;
    }
};
