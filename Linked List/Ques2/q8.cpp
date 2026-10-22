#include<iostream>
#include "../LL.h"
using namespace std;

// Delete All Occurrences in DLL
// https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1

class Solution {
  public:
    void deleteDLL(Node* curr, Node* &head, int x){     // head is passed by reference here. V.Imp
        if(curr == head){
            head = head->next;
            if(head != NULL){
                head->prev = NULL;
            }
            curr->next = NULL;
            delete(curr);
            return;
        }
        if(curr->next == NULL){ // tail
            curr->prev->next = NULL;
            curr->prev = NULL;
            delete(curr);
            return;
        }
        // normal node
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        
        curr->next = NULL;
        curr->prev = NULL;
        delete(curr);
    }
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp = head;
        while(temp != NULL){
            Node* curr = temp;
            temp = temp->next;
            if(curr->data == x){
                deleteDLL(curr, head, x);
            }
        }
        
        return head;
    }
};