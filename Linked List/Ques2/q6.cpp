#include<iostream>
#include "../LL.h"
using namespace std;

// Cycle Length in Linked List
// https://www.geeksforgeeks.org/problems/find-length-of-loop/1

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)    break;
        }
        
        if(fast == NULL || fast->next == NULL){
            return 0;
        }
        
        Node* temp = slow->next;
        int cnt = 1;
        while(temp != slow){
            cnt++;
            temp = temp->next;
        }
        
        return cnt;
    }
};