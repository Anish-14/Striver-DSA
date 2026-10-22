#include<iostream>
#include "../LL.h"          
using namespace std;

// sort 0,1,2 only in LL
// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        
        while(head != NULL){
            if(head->data == 0){
                zeroHead->next = new Node(0);
                zeroHead = zeroHead->next;
            }
            else if(head->data == 1){
                oneHead->next = new Node(1);
                oneHead = oneHead->next;
            }
            else{
                twoHead->next = new Node(2);
                twoHead = twoHead->next;
            }
            head = head->next;
        }
        
        if(one->next != NULL){
            zeroHead->next = one->next;
            oneHead->next = two->next;
        }
        else{
            zeroHead->next = two->next;
        }
        
        return zero->next;
        
    }
};
