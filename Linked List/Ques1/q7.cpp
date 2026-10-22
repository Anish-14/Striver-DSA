#include<iostream>
#include "../LL.h"          
using namespace std;

// Reverse a LL

// FIRST
void reverseLL1(Node* &head){
    // isme 1 naya pointer na bane for head so that it doesn't take any extra space.

    // base cases
    if(head == NULL  || head->next == NULL){
        return;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        head = prev;
    }

    return ;
}

Node* reverseLL2(Node* head){
    // difference between both input is that here an extra pointer is being created
    // dono hi existing LL me change karenge.

    if(head == NULL  || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    // Node* forward = NULL;

    while(curr != NULL){
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        // head = prev;
    }

    return prev;
}

//SECOND  
// Recursive way
Node* reverseLL3(Node* head){
    // base case 
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* temp = head;
    Node* chhotahead = reverseLL3(head->next);
    temp->next->next = temp;
    temp->next = NULL;

    return chhotahead;
}

void reverseUtil(Node* &head, Node* curr, Node* prev){
    // base case
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    reverseUtil(head,forward,curr);          // for next itertion sabko ek ek badha do.
    curr->next = prev;

    return;
}
Node* reverseLL4(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    reverseUtil(head,curr,prev);
    return head;
}
