#pragma once
#include <cstddef>

// 12 bytes of memory is used here 
class Node{
 public:
    int val;
    Node* next;

    Node(int val, Node* next){
        this->val = val;
        this->next = next;
    }
    
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

