#include<iostream>
#include "../LL.h"
using namespace std;

// Design Browser History
// https://leetcode.com/problems/design-browser-history/description/

class Node{
public:
    string val;
    Node *next, *prev;

    Node(string val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newPage = new Node(url);
        Node* temp = current->next;
        current->next = newPage;
        newPage->prev = current;
        current = current->next;

        // we should clear the memory as well
        while(temp){
            Node* curr = temp;
            temp = temp->next;
            delete(curr);
        }
    }
    
    string back(int steps) {
        while(steps && current->prev != NULL){
            current = current->prev;
            steps--;
        }

        return current->val;
    }
    
    string forward(int steps) {
        while(steps && current->next != NULL){
            current = current->next;
            steps--;
        }

        return current->val;
    }
};
