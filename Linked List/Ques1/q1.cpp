#include<iostream>
#include "../LL.h"          // this tells that the file is in the folder a step back "<>" if used this then the file need to be there in the current folder
using namespace std;

// Reverse a DLL
// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
  public:
    Node *reverse(Node *head) {
        Node* curr = head;
        while(curr->next != NULL){
            Node* temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            
            curr = curr->prev;
        }
        
        curr->next = curr->prev;
        curr->prev = NULL;
        
        return curr;
    }
};

