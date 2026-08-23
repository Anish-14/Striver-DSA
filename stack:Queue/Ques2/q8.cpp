#include<iostream>
#include<vector>
using namespace std;

// LRU Cache    --> Least Recent Used Cache
// https://leetcode.com/problems/lru-cache/description/


// Our DLL class
class Node{
public:
    int key, val;
    Node *next, *prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> mp;       // key, Node
    Node *head, *tail;                  // dummy head and tail to maintain the order smoothly
    
    void remove(Node* node){            // fun to remove a node from the DLL
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
    }

    void insert(Node* node){            // fun to add the node just after head
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            // if found then please first remove it and then return the val
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            // if key found then we've to reorder it to start so please delete it as we're going
            // to create a node and add it to DLL 
            remove(mp[key]);
            delete mp[key];
        }

        // create the node and add it to DLL
        mp[key] = new Node(key, value);
        insert(mp[key]);

        // if capacity is used then delete the lru
        if(mp.size() > capacity){
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */