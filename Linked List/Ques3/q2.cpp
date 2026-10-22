#include<iostream>
#include "../LL.h"
using namespace std;

// Remove duplicates from a sorted DLL
// https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1

class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        Node* temp = headRef;
        
        while(temp != NULL){
            Node* curr = temp;
            temp = temp->next;
            if(curr->prev && curr->data == curr->prev->data){
                curr->prev->next = temp;
                if(temp != NULL)
                    temp->prev = curr->prev;
                
                curr->prev = NULL;
                curr->next = NULL;
                
                delete(curr);
            }
        }
        
        return headRef;
    }
};