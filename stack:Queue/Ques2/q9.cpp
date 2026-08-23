#include<iostream>
#include<vector>
using namespace std;


//  LFU cache
//  https://leetcode.com/problems/lfu-cache/description/

class Node{
public: 
    int key, val, freq;
    Node *next, *prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->freq = 1;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DLL{
public:
    Node *head, *tail;
    int size;
    DLL(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addNode(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }
    void removeNode(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
        size--;
    }
    Node* removeTail(){
        if(size == 0)   return NULL;
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};
class LFUCache {
    int capacity, minFreq;
    unordered_map<int, Node*> keyTable;
    unordered_map<int, DLL*>  freqTable;

    void update(Node* node){
        int oldFreq = node->freq;
        freqTable[oldFreq]->removeNode(node);
        if(freqTable[oldFreq]->size == 0 && minFreq == oldFreq) minFreq++;

        node->freq++;
        if(freqTable.find(node->freq) == freqTable.end()){
            freqTable[node->freq] = new DLL();
        }

        freqTable[node->freq]->addNode(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyTable.find(key) != keyTable.end()){
            Node* node = keyTable[key];
            update(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyTable.find(key) != keyTable.end()){
            Node* node = keyTable[key];
            node->val = value;
            update(node);
            return;
        }

        if(keyTable.size() == capacity){
            Node* lfu = freqTable[minFreq]->removeTail();
            keyTable.erase(lfu->key);
            delete lfu;
        }

        minFreq = 1;
        Node* newNode = new Node(key, value);
        keyTable[key] = newNode;
        if(freqTable.find(1) == freqTable.end()){
            freqTable[1] = new DLL();
        }
        freqTable[1]->addNode(newNode);
    }
};









// using inbuilt list --> Same logic
#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
    int capacity, minFreq;
    // key -> {value, frequency}
    unordered_map<int, pair<int, int>> keyTable;
    // frequency -> list of keys (most recent at front)
    unordered_map<int, list<int>> freqTable;
    // key -> iterator to the key's position in the list
    unordered_map<int, list<int>::iterator> posTable;

    void update(int key, int value) {
        int freq = keyTable[key].second;
        freqTable[freq].erase(posTable[key]);
        if (freqTable[freq].empty()) {
            freqTable.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        
        freq++;
        keyTable[key] = {value, freq};
        freqTable[freq].push_front(key);
        posTable[key] = freqTable[freq].begin();
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (keyTable.find(key) == keyTable.end()) return -1;
        update(key, keyTable[key].first);
        return keyTable[key].first;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        if (keyTable.find(key) != keyTable.end()) {
            update(key, value);
            return;
        }

        if (keyTable.size() == capacity) {
            int evictKey = freqTable[minFreq].back();
            freqTable[minFreq].pop_back();
            if (freqTable[minFreq].empty()) freqTable.erase(minFreq);
            keyTable.erase(evictKey);
            posTable.erase(evictKey);
        }

        minFreq = 1;
        keyTable[key] = {value, 1};
        freqTable[1].push_front(key);
        posTable[key] = freqTable[1].begin();
    }
};




/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */








