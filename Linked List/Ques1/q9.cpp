#include<iostream>
#include "../LL.h"          
using namespace std;

// Add 1 to a Linked List Number
// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node* chhotaHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return chhotaHead;
}
void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
class Solution {
  public:
    Node* addOne(Node* head) {
        // reverse
        Node* temp = reverse(head);
        
        // add
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        
        int carry = 1;
        while(temp != NULL){
            int sum = temp->data + carry;
            curr->next = new Node(sum%10);
            curr = curr->next;
            carry = sum/10;
            temp = temp->next;
        }
        if(carry){
            curr->next = new Node(carry);
        }
        
        curr = dummy->next;
        dummy->next = NULL;
        delete(dummy);
        
        Node* ans = reverse(curr);
        
        return ans;
    }
};
