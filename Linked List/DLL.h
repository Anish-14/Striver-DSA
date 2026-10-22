#pragma once
#include <cstddef>

class DLLNode{
    // 12 bytes of memory used here 
 public:
    int val;
    DLLNode* next;
    DLLNode* prev;
    
    DLLNode(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};