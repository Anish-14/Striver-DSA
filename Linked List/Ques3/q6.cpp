#include<iostream>
#include "../LL.h"
using namespace std;

// Flattening a Linked List
// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

// Attempt this problem
// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/



// According to new GFG test case this solution will give you TLE so do check out there 
// heap solution in the editorials
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; 

class Solution {
  public:
    Node* merge(Node* temp1, Node* temp2){
        Node* dummy = new Node(-1);
        Node* ans = dummy;
        
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->data < temp2->data){
                ans->bottom = temp1;
                temp1 = temp1->bottom;
            }
            else{
                ans->bottom = temp2;
                temp2 = temp2->bottom;
            }
            ans = ans->bottom;
        }
        while(temp1 != NULL){
            ans->bottom = temp1;
            temp1 = temp1->bottom;
            ans = ans->bottom;
        }
        while(temp2 != NULL){
            ans->bottom = temp2;
            temp2 = temp2->bottom;
            ans = ans->bottom;
        }
        
        return dummy;
    }
    Node *flatten(Node *root) {
        // we gotta maintain the order as well here
        if(root == NULL || root->next == NULL){
            return root;
        }
        
        Node* nextHead = flatten(root->next);
        
        // Let's do this iteration
        Node* temp = root;
        temp->next = NULL;
        
        // merge two sorted LL
        Node* mergedHead = merge(root, nextHead);
        Node* ans = mergedHead->bottom;
        mergedHead->bottom = NULL;
        delete(mergedHead);
        
        return ans;
    }
};