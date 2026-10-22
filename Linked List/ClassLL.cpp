#include<iostream>
using namespace std;

class Node{
    // 12 bytes of memory used here 
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


int main(){
    Node w = Node(27);          
    Node* y = new Node(23);
    Node* x = new Node(24, nullptr);

    cout<<w.val<<endl;      // we'll have to use .val here to extract value because it is not in heap memeory
    cout<<y<<endl;          // memory address
    cout<<y->val<<endl;     // value at that memory address
}

