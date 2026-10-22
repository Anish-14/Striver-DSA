#include<iostream>
#include "../LL.h"
using namespace std;

// Copy List with Random Pointer
// https://leetcode.com/problems/copy-list-with-random-pointer/description/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // First we'll copy the LL with the next pointers only
        Node* dummy = new Node(-1);
        Node* ans = dummy;
        Node* temp = head;

        while(temp != NULL){
            ans->next = new Node(temp->val);
            ans = ans->next;
            temp = temp->next;
        } 


        // Now we want the random pointers as well

        // Build the zig-zag connections
        ans = dummy->next;
        temp = head;

        while(temp != NULL){
            Node* next1 = temp->next;
            Node* next2 = ans->next;

            temp->next = ans;
            ans->next = next1;

            temp = next1;
            ans = next2;
        }

        // Point the random pointers
        ans = dummy->next;
        temp = head;

        while(temp != NULL){
            if(temp->random == NULL){
                temp->next->random = NULL;
            }
            else{
                temp->next->random = temp->random->next;
            }

            temp = temp->next->next;
        }


        // please adjust back the next pointers
        ans = dummy->next;
        temp = head;

        while(temp != NULL){
            temp->next = temp->next->next;
            ans->next = (ans->next == NULL) ? NULL : ans->next->next;

            temp = temp->next;
            ans = ans->next;
        }

        ans = dummy->next;
        return ans;
    }
};